#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int n, m, op, l, r, x, a[100005];

// Segment Tree
void pushup(int);
void build(int, int, int);
void modify(int, int, int, int);
void modify(int, int, int);
long long query(int, int, int);

signed main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        cin >> op >> l >> r;
        if (op == 1) {
            cout << query(1, l, r) << endl;
        } else if (op == 2) {
            cin >> x;
            modify(1, l, r, x);
        } else {
            modify(1, l, r);
        }
    }
    return 0;
}

// === Segment Tree ===

struct node {
    int l, r;
    long long s, m;

    node()
        : l(0),
          r(0),
          s(0),
          m(0) {}

    node(int _l, int _r)
        : l(_l),
          r(_r),
          s(0),
          m(0) {}
} tr[100005 << 2];

inline void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    tr[u].m = std::max(tr[u << 1].m, tr[u << 1 | 1].m);
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = tr[u].m = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int d) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].s = tr[u].m = d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) {
        modify(u << 1, x, d);
    } else {
        modify(u << 1 | 1, x, d);
    }
    pushup(u);
}

void modify(int u, int l, int r, int d) {
    if (tr[u].m < d) return;
    if (tr[u].l == tr[u].r) {
        tr[u].s = tr[u].m %= d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);
    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].s;
    int mid = tr[u].l + tr[u].r >> 1;
    long long sum = 0;
    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}
