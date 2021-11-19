#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    long long d, s;

    node() {
        l = r = 0;
        s = 0;
        d = 0;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        s = 0;
        d = 0;
    }
} tr[200005 << 3];
int n, f, op, x, y, k, a[200005];

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

void pushdown(int u) {
    tr[u << 1].d += tr[u].d;
    tr[u << 1].s += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].d;
    tr[u << 1 | 1].d += tr[u].d;
    tr[u << 1 | 1].s += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].d;
    tr[u].d = 0;
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

long long query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    long long s = 0;
    pushdown(u);
    if (l <= mid) s += query(u << 1, l, r);
    if (r > mid) s += query(u << 1 | 1, l, r);
    return s;
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

int main() {
    cin >> n >> f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (f--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            modify(1, x, y, k);
        } else if (op == 2) {
            cin >> k;
            modify(1, 1, 1, k);
        } else if (op == 3) {
            cin >> k;
            modify(1, 1, 1, -k);
        } else if (op == 4) {
            cin >> x >> y;
            cout << query(1, x, y) << endl;
        } else if (op == 5) {
            cout << query(1, 1, 1) << endl;
        }
    }
    return 0;
}
