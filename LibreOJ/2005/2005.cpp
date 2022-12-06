#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

struct node {
    int l, r;
    __int128 sum_x, sum_y, sum_xx, sum_xy;
    __int128 lazy_s, lazy_t;
    bool covered;

    node(const int &_l = 0, const int &_r = 0)
        : l(_l),
          r(_r),
          sum_x(0),
          sum_y(0),
          sum_xx(0),
          sum_xy(0),
          lazy_s(0),
          lazy_t(0),
          covered(false) {}

    node operator+(const node &rhs) const {
        node res;

        res.l = l;
        res.r = rhs.r;
        res.sum_x = sum_x + rhs.sum_x;
        res.sum_y = sum_y + rhs.sum_y;
        res.sum_xx = sum_xx + rhs.sum_xx;
        res.sum_xy = sum_xy + rhs.sum_xy;

        return res;
    }
} tr[N << 2];

int n, m, x[N], y[N];

__int128 square_sum(__int128 x) {
    return x * (x + 1) * (2 * x + 1) / 6;
}

__int128 square_sum(__int128 l, __int128 r) {
    return square_sum(r) - square_sum(l - 1);
}

/// Add (s, t) to each element under tr[u]
void modify_node(int u, __int128 s, __int128 t) {
    tr[u].lazy_s += s;
    tr[u].lazy_t += t;

    tr[u].sum_xx += 2 * s * tr[u].sum_x + s * s * (tr[u].r - tr[u].l + 1);
    tr[u].sum_xy += t * tr[u].sum_x + s * tr[u].sum_y + s * t * (tr[u].r - tr[u].l + 1);

    tr[u].sum_x += s * (tr[u].r - tr[u].l + 1);
    tr[u].sum_y += t * (tr[u].r - tr[u].l + 1);
}

/// x[i] = y[i] = i
void change_node(int u) {
    tr[u].lazy_s = tr[u].lazy_t = 0;
    tr[u].sum_x = tr[u].sum_y = static_cast<__int128>(tr[u].l + tr[u].r) * (tr[u].r - tr[u].l + 1) / 2;
    tr[u].sum_xx = tr[u].sum_xy = square_sum(tr[u].l, tr[u].r);
    tr[u].covered = true;
}

void pushup(int u) {
    tr[u] = tr[u << 1] + tr[u << 1 | 1];
}

void pushdown(int u) {
    if (tr[u].covered) {
        change_node(u << 1);
        change_node(u << 1 | 1);

        tr[u].covered = false;
    }

    modify_node(u << 1, tr[u].lazy_s, tr[u].lazy_t);
    modify_node(u << 1 | 1, tr[u].lazy_s, tr[u].lazy_t);

    tr[u].lazy_s = tr[u].lazy_t = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) {
        tr[u].sum_x = x[l];
        tr[u].sum_y = y[l];
        tr[u].sum_xx = static_cast<__int128>(x[l]) * x[l];
        tr[u].sum_xy = static_cast<__int128>(x[l]) * y[l];

        return;
    }

    int mid = l + r >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(u);
}

void modify(int u, int l, int r, __int128 s, __int128 t) {
    if (l <= tr[u].l && tr[u].r <= r) {
        modify_node(u, s, t);

        return;
    }

    int mid = tr[u].l + tr[u].r >> 1;

    pushdown(u);

    if (l <= mid) modify(u << 1, l, r, s, t);
    if (r > mid) modify(u << 1 | 1, l, r, s, t);

    pushup(u);
}

void change(int u, int l, int r, __int128 s, __int128 t) {
    if (l <= tr[u].l && tr[u].r <= r) {
        change_node(u);
        modify_node(u, s, t);

        return;
    }

    int mid = tr[u].l + tr[u].r >> 1;

    pushdown(u);

    if (l <= mid) change(u << 1, l, r, s, t);
    if (r > mid) change(u << 1 | 1, l, r, s, t);

    pushup(u);
}

node query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u];

    int mid = tr[u].l + tr[u].r >> 1;
    node res;

    pushdown(u);

    if (l <= mid) res = res + query(u << 1, l, r);
    if (r > mid) res = res + query(u << 1 | 1, l, r);

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }

    build(1, 1, n);

    while (m--) {
        int op, l, r;

        cin >> op >> l >> r;

        if (op == 1) {
            auto res = query(1, l, r);

            double x = static_cast<double>(res.sum_xy) - static_cast<double>(res.sum_x) * res.sum_y / (r - l + 1),
                   y = static_cast<double>(res.sum_xx) - static_cast<double>(res.sum_x) * res.sum_x / (r - l + 1);

            cout << std::fixed << std::setprecision(10) << x / y << endl;
        } else if (op == 2) {
            int s, t;

            cin >> s >> t;

            modify(1, l, r, s, t);
        } else {  // op == 3
            int s, t;

            cin >> s >> t;

            change(1, l, r, s, t);
        }
    }

    return 0;
}
