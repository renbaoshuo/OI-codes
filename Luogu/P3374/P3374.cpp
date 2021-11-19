#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r, s;

    node() {
        l = r = s = 0;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        s = 0;
    }
} tr[500005 << 2];
int n, m, op, x, y, a[500005];

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
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

void change(int u, int x, int d) {
    if (tr[u].l == tr[u].r) {
        tr[u].s += d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) {
        change(u << 1, x, d);
    } else {
        change(u << 1 | 1, x, d);
    }
    pushup(u);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int s = 0;
    if (l <= mid) s += query(u << 1, l, r);
    if (r > mid) s += query(u << 1 | 1, l, r);
    return s;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        cin >> op >> x >> y;
        if (op == 1) {
            change(1, x, y);
        } else if (op == 2) {
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}
