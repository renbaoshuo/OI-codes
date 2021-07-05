#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r, min;

    node() {
        l = r = 0;
        min = 0x3f3f3f3f;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        min = 0x3f3f3f3f;
    }
} tr[25005 << 2];
int n, q, x, y, a[25005];

void pushup(int u) {
    tr[u].min = min(tr[u << 1].min, tr[u << 1 | 1].min);
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].min = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].min;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int s = 0x3f3f3f3f;
    if (l <= mid) s = min(s, query(u << 1, l, r));
    if (r > mid) s = min(s, query(u << 1 | 1, l, r));
    return s;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << query(1, x, y) << endl;
    }
    return 0;
}
