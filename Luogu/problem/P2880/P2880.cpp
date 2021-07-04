#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r, max, min;

    node() {
        l = r = max = 0;
        min = 0x3f3f3f3f;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        max = 0;
        min = 0x3f3f3f3f;
    }
} tr[50005 << 2];
int n, q, a, b, h[50005];

void pushup(int u) {
    tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
    tr[u].min = min(tr[u << 1].min, tr[u << 1 | 1].min);
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].max = h[l];
        tr[u].min = h[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query_max(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].max;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int s = 0;
    if (l <= mid) s = max(s, query_max(u << 1, l, r));
    if (r > mid) s = max(s, query_max(u << 1 | 1, l, r));
    return s;
}

int query_min(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].min;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int s = 0x3f3f3f3f;
    if (l <= mid) s = min(s, query_min(u << 1, l, r));
    if (r > mid) s = min(s, query_min(u << 1 | 1, l, r));
    return s;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    build(1, 1, n);
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << query_max(1, a, b) - query_min(1, a, b) << endl;
    }
    return 0;
}
