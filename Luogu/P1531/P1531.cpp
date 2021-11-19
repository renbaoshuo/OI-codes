#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    int max;

    node() {
        l = r = 0;
        max = -0x3f3f3f3f;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        max = -0x3f3f3f3f;
    }
} tr[200005 << 2];
int n, m, x, y, a[200005];
char op;

void pushup(int u) {
    tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].max = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int d) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].max = max(tr[u].max, d);
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

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].max;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if (l <= mid) {
        v = query(u << 1, l, r);
    }
    if (r > mid) {
        v = max(v, query(u << 1 | 1, l, r));
    }
    return v;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        cin >> op >> x >> y;
        if (op == 'U') {
            modify(1, x, y);
        } else if (op == 'Q') {
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}
