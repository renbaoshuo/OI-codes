#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int n, m, d, s, t, a[1000005];

// Segment Tree
void pushup(int);
void pushdown(int);
void build(int, int, int);
void modify(int, int, int, int);
int query(int, int, int);

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        cin >> d >> s >> t;
        if (query(1, s, t) < d) {
            cout << -1 << endl
                 << i << endl;
            exit(0);
        } else {
            modify(1, s, t, -d);
        }
    }
    cout << 0 << endl;
    return 0;
}

// === Segment Tree ===

struct node {
    int l, r, m, d;

    node()
        : l(0), r(0), m(std::numeric_limits<int>::max()), d(0) {}

    node(int _l, int _r)
        : l(_l), r(_r), m(std::numeric_limits<int>::max()), d(0) {}
} tr[1000005 << 1];

void pushup(int u) {
    tr[u].m = std::min(tr[u << 1].m, tr[u << 1 | 1].m);
}

void pushdown(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    left.m += root.d;
    left.d += root.d;
    right.m += root.d;
    right.d += root.d;
    root.d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].m = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int k) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].m += k;
        tr[u].d += k;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r, k);
    if (r > mid) modify(u << 1 | 1, l, r, k);
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].m;
    int mid = tr[u].l + tr[u].r >> 1;
    int min = std::numeric_limits<int>::max();
    pushdown(u);
    if (l <= mid) min = std::min(min, query(u << 1, l, r));
    if (r > mid) min = std::min(min, query(u << 1 | 1, l, r));
    return min;
}
