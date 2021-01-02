#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    long long s, d, x;

    node() {
        l = r = s = d = 0;
        x = 1;
    }
    node(int _l, int _r) {
        l = _l, r = _r;
        s = d = 0;
        x = 1;
    }
} tr[100005 << 2];
int n, m, p, op, x, y;
long long k, a[100005];

void pushup(int u) {
    tr[u].s = (tr[u << 1].s + tr[u << 1 | 1].s) % p;
}

void pushdown(int u) {
    tr[u << 1].s = ((tr[u << 1].s * tr[u].x) + (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].d) % p;
    tr[u << 1].x = tr[u << 1].x * tr[u].x % p;
    tr[u << 1].d = (tr[u << 1].d * tr[u].x + tr[u].d) % p;
    tr[u << 1 | 1].s = ((tr[u << 1 | 1].s * tr[u].x) + (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].d) % p;
    tr[u << 1 | 1].x = tr[u << 1 | 1].x * tr[u].x % p;
    tr[u << 1 | 1].d = (tr[u << 1 | 1].d * tr[u].x + tr[u].d) % p;
    tr[u].d = 0;
    tr[u].x = 1;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = a[l] % p;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, long long x, long long d) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].s = ((tr[u].s * x) + (tr[u].r - tr[u].l + 1) * d) % p;
        tr[u].x = tr[u].x * x % p;
        tr[u].d = (tr[u].d * x + d) % p;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r, x, d);
    if (r > mid) modify(u << 1 | 1, l, r, x, d);
    pushup(u);
}

long long query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    long long s = 0;
    pushdown(u);
    if (l <= mid) s = query(u << 1, l, r);
    if (r > mid) s = (s + query(u << 1 | 1, l, r)) % p;
    return s;
}

signed main() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> m;
    while (m--) {
        cin >> op >> x >> y;
        if (op == 1) {
            cin >> k;
            modify(1, x, y, k, 0);
        } else if (op == 2) {
            cin >> k;
            modify(1, x, y, 1, k);
        } else if (op == 3) {
            cout << query(1, x, y) % p << endl;
        }
    }
    return 0;
}