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
} tr[1000005 << 2];
int n, w, x, b, ans;

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

void modify(int u, int p, int d) {
    if (tr[u].l == p == tr[u].r) {
        tr[u].s += d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (p <= mid) {
        modify(u << 1, p, d);
    } else {
        modify(u << 1 | 1, p, d);
    }
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int s = 0;
    if (l <= mid) s += query(u << 1, l, r);
    if (r > mid) s += query(u << 1 | 1, l, r);
    return s;
}

int main() {
    cin >> n >> w;
    build(1, 1, 100000);
    for (int i = 0; i < n; i++) {
        cin >> x >> b;
        modify(1, x, b);
    }
    for (int i = 1; i + w <= 100000; i++) {
        ans = max(ans, query(1, i, i + w - 1));
    }
    cout << ans << endl;
    return 0;
}
