#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    long long s;

    node() {
        l = r = 0;
        s = 0;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        s = 0;
    }
} tr[100005 << 2];
int t, q, mod, op, m;

void pushup(int u) {
    tr[u].s = (tr[u << 1].s * tr[u << 1 | 1].s) % mod;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = 1;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r) {
        tr[u].s = v;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) {
        modify(u << 1, x, v);
    }
    else {
        modify(u << 1 | 1, x, v);
    }
    pushup(u);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> q >> mod;
        build(1, 1, q);
        for (int i = 1; i <= q; i++) {
            cin >> op >> m;
            if (op == 1) {
                modify(1, i, m);
            }
            else if (op == 2) {
                modify(1, m, 1);
            }
            cout << tr[1].s << endl;
        }
    }
    return 0;
}
