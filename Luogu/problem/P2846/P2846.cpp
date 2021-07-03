#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r, s, d;

    node() {
        l = r = s = d = 0;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        s = d = 0;
    }
} tr[100005 << 2];
int n, m, op, s, e;

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

void pushdown(int u) {
    if (!tr[u].d) return;
    tr[u << 1].d = !tr[u << 1].d;
    tr[u << 1 | 1].d = !tr[u << 1 | 1].d;
    tr[u << 1].s = tr[u << 1].r - tr[u << 1].l + 1 - tr[u << 1].s;
    tr[u << 1 | 1].s = tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1 - tr[u << 1 | 1].s;
    tr[u].d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].d = !tr[u].d;
        tr[u].s = tr[u].r - tr[u].l + 1 - tr[u].s;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r);
    if (r > mid) modify(u << 1 | 1, l, r);
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
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
    for(int i = 0 ; i < m ; i++) {
        cin >> op >> s >> e;
        if(op == 0) {
            modify(1, s, e);
        } else if(op == 1) {
            cout << query(1, s, e) << endl;
        }
    }
    return 0;
}
