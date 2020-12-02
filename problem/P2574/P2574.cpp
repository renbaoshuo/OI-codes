#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    int s, d;
    node() {
        l = r = s = d = 0;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        s = d = 0;
    }
} tr[200005 << 2];
int n, m, op, x, y, a[200005];

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

void pushdown(int u) {
    if (tr[u].d) {
        tr[u << 1].d ^= tr[u].d;
        tr[u << 1].s = (tr[u << 1].r - tr[u << 1].l + 1) - tr[u << 1].s;
        tr[u << 1 | 1].d ^= tr[u].d;
        tr[u << 1 | 1].s = (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) - tr[u << 1 | 1].s;
        tr[u].d = 0;
    }
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].d ^= 1;
        tr[u].s = (tr[u].r - tr[u].l + 1) - tr[u].s;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) {
        modify(u << 1, l, r);
    }
    if (r > mid) {
        modify(u << 1 | 1, l, r);
    }
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
    for (int i = 1; i <= n; i++) {
        scanf("%1d", &a[i]);
    }
    build(1, 1, n);
    while (m--) {
        cin >> op >> x >> y;
        if (op == 0) {
            modify(1, x, y);
        }
        else if (op == 1) {
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}
