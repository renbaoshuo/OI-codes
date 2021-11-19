#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r, v;

    node() {
        l = r = 0;
        v = -0x3f3f3f3f;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        v = -0x3f3f3f3f;
    }
} tr[200005 << 2];
int m, p;
char op;

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void pushup(int u) {
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if (l <= mid) v = query(u << 1, l, r);
    if (r > mid) v = max(v, query(u << 1 | 1, l, r));
    return v;
}

void modify(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].v = v;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid)
        modify(u << 1, x, v);
    else
        modify(u << 1 | 1, x, v);
    pushup(u);
}

int main() {
    cin >> m >> p;
    int n = 0, x, a = 0;
    build(1, 1, m);
    while (m--) {
        cin >> op >> x;
        if (op == 'Q') {
            a = query(1, n - x + 1, n);
            cout << a << endl;
        } else {
            modify(1, ++n, (a + x) % p);
        }
    }
    return 0;
}
