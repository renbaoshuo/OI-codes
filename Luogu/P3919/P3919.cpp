#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, m, a[N], root[N], cnt;

struct node {
    int l, r, v;
} tr[N << 6];

int build(int l, int r) {
    int p = ++cnt;

    if (l == r) {
        tr[p].v = a[l];

        return p;
    }

    int mid = l + r >> 1;

    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);

    return p;
}

int modify(int u, int l, int r, int p, int v) {
    int q = ++cnt;

    tr[q] = tr[u];

    if (l == r) {
        a[p] = v;
        tr[q].v = v;

        return q;
    }

    int mid = l + r >> 1;

    if (p <= mid) {
        tr[q].l = modify(tr[u].l, l, mid, p, v);
    } else {
        tr[q].r = modify(tr[u].r, mid + 1, r, p, v);
    }

    return q;
}

int query(int u, int l, int r, int p) {
    if (l == r) return tr[u].v;

    int mid = l + r >> 1;

    if (p <= mid) {
        return query(tr[u].l, l, mid, p);
    }

    return query(tr[u].r, mid + 1, r, p);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    root[0] = build(1, n);

    for (int i = 1, ver, op; i <= m; i++) {
        cin >> ver >> op;

        if (op == 1) {
            int p, v;

            cin >> p >> v;

            root[i] = modify(root[ver], 1, n, p, v);
        } else {  // op == 2
            int p;

            cin >> p;

            cout << query(root[ver], 1, n, p) << endl;

            root[i] = root[ver];
        }
    }

    return 0;
}
