#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m;
long long a[N];

struct node {
    int l, r;
    long long min, max, sum, tag;

    node(const int &_l = 0, const int &_r = 0)
        : l(_l), r(_r), min(0), max(0), sum(0), tag(0) {}
} tr[N << 2];

void pushup(int u) {
    tr[u].min = std::min(tr[u << 1].min, tr[u << 1 | 1].min);
    tr[u].max = std::max(tr[u << 1].max, tr[u << 1 | 1].max);
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
    if (!tr[u].tag) return;

    tr[u << 1].min += tr[u].tag;
    tr[u << 1].max += tr[u].tag;
    tr[u << 1].sum += tr[u].tag * (tr[u << 1].r - tr[u << 1].l + 1);
    tr[u << 1].tag += tr[u].tag;

    tr[u << 1 | 1].min += tr[u].tag;
    tr[u << 1 | 1].max += tr[u].tag;
    tr[u << 1 | 1].sum += tr[u].tag * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
    tr[u << 1 | 1].tag += tr[u].tag;

    tr[u].tag = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) {
        tr[u].min = tr[u].max = tr[u].sum = a[l];

        return;
    }

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(u);
}

void modify_add(int u, int l, int r, long long x) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].sum += x * (tr[u].r - tr[u].l + 1);
        tr[u].tag += x;
        tr[u].min += x;
        tr[u].max += x;

        return;
    }

    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (l <= mid) modify_add(u << 1, l, r, x);
    if (r > mid) modify_add(u << 1 | 1, l, r, x);

    pushup(u);
}

void modify_sqrt(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        long long sqrt_max = std::sqrt(tr[u].max),
                  sqrt_min = std::sqrt(tr[u].min);

        if (sqrt_max - tr[u].max == sqrt_min - tr[u].min) {
            modify_add(u, l, r, sqrt_max - tr[u].max);

            return;
        }
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    pushdown(u);

    if (l <= mid) modify_sqrt(u << 1, l, r);
    if (r > mid) modify_sqrt(u << 1 | 1, l, r);

    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].sum;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;
    long long res = 0;

    pushdown(u);

    if (l <= mid) res += query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int l, r;
            long long x;

            cin >> l >> r >> x;

            modify_add(1, l, r, x);
        } else if (op == 2) {
            int l, r;

            cin >> l >> r;

            modify_sqrt(1, l, r);
        } else {  // op == 3
            int l, r;

            cin >> l >> r;

            cout << query(1, l, r) << endl;
        }
    }

    return 0;
}
