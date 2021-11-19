#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r, v, d;

    node() {
        l = r = 0;
        v = d = 0;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        v = d = 0;
    }
} tr[100005 << 2];
int n, m, t, x, y;

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void pushdown(int u) {
    tr[u << 1].d ^= tr[u].d;
    tr[u << 1 | 1].d ^= tr[u].d;
    tr[u].d = 0;
}

void change(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].d ^= 1;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) change(u << 1, l, r);
    if (r > mid) change(u << 1 | 1, l, r);
}

int query(int u, int x) {
    if (tr[u].l == tr[u].r) {
        tr[u].v ^= tr[u].d;
        tr[u].d = 0;
        return tr[u].v;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (x <= mid) return query(u << 1, x);
    return query(u << 1 | 1, x);
}

int main() {
    cin >> n >> m;
    build(1, 1, n);
    while (m--) {
        cin >> t >> x;
        if (t == 1) {
            cin >> y;
            change(1, x, y);
        } else {
            cout << query(1, x) << endl;
        }
    }
    return 0;
}