#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    int min;

    node() {
        l = r = 0;
        min = 0x3f3f3f3f;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        min = 0x3f3f3f3f;
    }
} tr[100005 << 2];
int n, m, x, y, a[100005];

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
    int ans = 0x3f3f3f3f;
    if (l <= mid) {
        ans = query(u << 1, l, r);
    }
    if (r > mid) {
        ans = min(ans, query(u << 1 | 1, l, r));
    }
    return ans;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    build(1, 1, m);
    while (n--) {
        cin >> x >> y;
        cout << query(1, x, y) << ' ';
    }
    cout << endl;
    return 0;
}
