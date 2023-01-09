#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, a[N];

struct node {
    int l, r;
    long long sum;
    int max, max_2nd,
        min, min_2nd;
    int cnt_max, cnt_min;
    int tag_add, tag_max, tag_min;

    node(const int &_l = 0, const int &_r = 0)
        : l(_l),
          r(_r),
          sum(0),
          max(0),
          max_2nd(-INF),
          min(0),
          min_2nd(INF),
          cnt_max(1),
          cnt_min(1),
          tag_add(0),
          tag_max(-INF),
          tag_min(INF) {}
} tr[N << 2];

void pushup(int u) {
    auto &p = tr[u],
         &l = tr[u << 1],
         &r = tr[u << 1 | 1];

    p.sum = l.sum + r.sum;

    if (l.max == r.max) {
        p.max = l.max;
        p.max_2nd = std::max(l.max_2nd, r.max_2nd);
        p.cnt_max = l.cnt_max + r.cnt_max;
    } else if (l.max > r.max) {
        p.max = l.max;
        p.max_2nd = std::max(l.max_2nd, r.max);
        p.cnt_max = l.cnt_max;
    } else {  // l.max < r.max
        p.max = r.max;
        p.max_2nd = std::max(l.max, r.max_2nd);
        p.cnt_max = r.cnt_max;
    }

    if (l.min == r.min) {
        p.min = l.min;
        p.min_2nd = std::min(l.min_2nd, r.min_2nd);
        p.cnt_min = l.cnt_min + r.cnt_min;
    } else if (l.min < r.min) {
        p.min = l.min;
        p.min_2nd = std::min(l.min_2nd, r.min);
        p.cnt_min = l.cnt_min;
    } else {  // l.min > r.min
        p.min = r.min;
        p.min_2nd = std::min(l.min, r.min_2nd);
        p.cnt_min = r.cnt_min;
    }
}

void push_add(int u, int x) {
    tr[u].sum += static_cast<long long>(tr[u].r - tr[u].l + 1) * x;

    tr[u].max += x;
    if (tr[u].max_2nd != -INF) tr[u].max_2nd += x;
    if (tr[u].tag_max != -INF) tr[u].tag_max += x;

    tr[u].min += x;
    if (tr[u].min_2nd != INF) tr[u].min_2nd += x;
    if (tr[u].tag_min != INF) tr[u].tag_min += x;

    tr[u].tag_add += x;
}

void push_max(int u, int x) {
    if (x <= tr[u].min) return;

    tr[u].sum += static_cast<long long>(x - tr[u].min) * tr[u].cnt_min;

    if (tr[u].max_2nd == tr[u].min) tr[u].max_2nd = x;
    if (tr[u].max == tr[u].min) tr[u].max = x;

    tr[u].min = x;
    tr[u].tag_min = std::max(tr[u].tag_min, x);
    tr[u].tag_max = x;
}

void push_min(int u, int x) {
    if (tr[u].max <= x) return;

    tr[u].sum += static_cast<long long>(x - tr[u].max) * tr[u].cnt_max;

    if (tr[u].min_2nd == tr[u].max) tr[u].min_2nd = x;
    if (tr[u].min == tr[u].max) tr[u].min = x;

    tr[u].max = x;
    tr[u].tag_max = std::min(tr[u].tag_max, x);
    tr[u].tag_min = x;
}

void pushdown(int u) {
    if (tr[u].tag_add) {
        push_add(u << 1, tr[u].tag_add);
        push_add(u << 1 | 1, tr[u].tag_add);
        tr[u].tag_add = 0;
    }

    if (tr[u].tag_max != -INF) {
        push_max(u << 1, tr[u].tag_max);
        push_max(u << 1 | 1, tr[u].tag_max);
        tr[u].tag_max = -INF;
    }

    if (tr[u].tag_min != INF) {
        push_min(u << 1, tr[u].tag_min);
        push_min(u << 1 | 1, tr[u].tag_min);
        tr[u].tag_min = INF;
    }
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) {
        tr[u].sum = tr[u].max = tr[u].min = a[l];

        return;
    }

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(u);
}

/**
 * 对于所有的 i ∈ [l, r]，将 a[i] 加上 k
 */
void modify_add(int u, int l, int r, int x) {
    if (l <= tr[u].l && tr[u].r <= r) {
        push_add(u, x);

        return;
    }

    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (l <= mid) modify_add(u << 1, l, r, x);
    if (r > mid) modify_add(u << 1 | 1, l, r, x);

    pushup(u);
}

/**
 * 对于所有的 i ∈ [l, r]，将 a[i] 变为 max(a[i], v)
 */
void modify_max(int u, int l, int r, int x) {
    if (x <= tr[u].min) return;

    if (l <= tr[u].l && tr[u].r <= r && x < tr[u].min_2nd) {
        push_max(u, x);

        return;
    }

    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (l <= mid) modify_max(u << 1, l, r, x);
    if (r > mid) modify_max(u << 1 | 1, l, r, x);

    pushup(u);
}

/**
 * 对于所有的 i ∈ [l, r]，将 a[i] 变为 min(a[i], v)
 */
void modify_min(int u, int l, int r, int x) {
    if (tr[u].max <= x) return;

    if (l <= tr[u].l && tr[u].r <= r && tr[u].max_2nd < x) {
        push_min(u, x);

        return;
    }

    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (l <= mid) modify_min(u << 1, l, r, x);
    if (r > mid) modify_min(u << 1 | 1, l, r, x);

    pushup(u);
}

long long query_sum(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1;
    long long res = 0;

    if (l <= mid) res += query_sum(u << 1, l, r);
    if (r > mid) res += query_sum(u << 1 | 1, l, r);

    return res;
}

int query_max(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].max;

    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1,
        res = -INF;

    if (l <= mid) res = std::max(res, query_max(u << 1, l, r));
    if (r > mid) res = std::max(res, query_max(u << 1 | 1, l, r));

    return res;
}

int query_min(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].min;

    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1,
        res = INF;

    if (l <= mid) res = std::min(res, query_min(u << 1, l, r));
    if (r > mid) res = std::min(res, query_min(u << 1 | 1, l, r));

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    cin >> m;

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int l, r, x;

            cin >> l >> r >> x;

            modify_add(1, l, r, x);
        } else if (op == 2) {
            int l, r, x;

            cin >> l >> r >> x;

            modify_max(1, l, r, x);
        } else if (op == 3) {
            int l, r, x;

            cin >> l >> r >> x;

            modify_min(1, l, r, x);
        } else if (op == 4) {
            int l, r;

            cin >> l >> r;

            cout << query_sum(1, l, r) << endl;
        } else if (op == 5) {
            int l, r;

            cin >> l >> r;

            cout << query_max(1, l, r) << endl;
        } else {  // op == 6
            int l, r;

            cin >> l >> r;

            cout << query_min(1, l, r) << endl;
        }
    }

    return 0;
}
