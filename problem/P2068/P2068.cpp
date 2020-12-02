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
} tr[1000005 << 2];
long long n, w, a, b;
char op;

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int x, int d) {
    if (tr[u].l == tr[u].r) {
        tr[u].s += d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) modify(u << 1, x, d);
    else modify(u << 1 | 1, x, d);
    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    long long s = 0;
    if (l <= mid) s += query(u << 1, l, r);
    if (r > mid) s += query(u << 1 | 1, l, r);
    return s;
}

int main() {
    cin >> n >> w;
    build(1, 1, n);
    while (w--) {
        cin >> op >> a >> b;
        if (op == 'x') {
            modify(1, a, b);
        }
        else if (op == 'y') {
            cout << query(1, a, b) << endl;
        }
    }
    return 0;
}
