#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    int s, d;

    node() {}
    node(int _l, int _r) {
        l = _l;
        r = _r;
        s = d = 0;
    }
} tr[10000005 << 2];
int n, m, op, x, y, k;

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

void pushdown(int u) {
    if (!tr[u].d) return;
    tr[u << 1].d += tr[u].d;
    tr[u << 1].s += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].d;
    tr[u << 1 | 1].d += tr[u].d;
    tr[u << 1 | 1].s += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].d;
    tr[u].d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int d) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].d += d;
        tr[u].s += (tr[u].r - tr[u].l + 1) * d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);
    pushup(u);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int s = 0;
    pushdown(u);
    if (l <= mid) s += query(u << 1, l, r);
    if (r > mid) s += query(u << 1 | 1, l, r);
    return s;
}

int main() {
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        cin >> op >> x;
        if (op == 0) {
            cin >> y;
            modify(1, x, y, 1);
        }
        else if (op == 1) {
            cout << query(1, x, x) << endl;
        }
    }
    return 0;
}
