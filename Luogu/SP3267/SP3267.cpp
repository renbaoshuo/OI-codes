#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 300005;

int n, q, a[N], pre[N];
std::map<int, int> map;

// Segment Tree
int cnt, root[N];
int build(int, int);
int insert(int, int, int);
int query(int, int);

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    root[0] = build(1, n);
    for (int i = 1; i <= n; i++) {
        if (!map.count(a[i])) {
            root[i] = insert(root[i - 1], i, 1);
        } else {
            int tmp = insert(root[i - 1], map[a[i]], -1);
            root[i] = insert(tmp, i, 1);
        }
        map[a[i]] = i;
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(root[r], l) << endl;
    }
    return 0;
}

// === Segment Tree ===

struct node {
    int l, r, c;
    int lid, rid;

    node()
        : l(0), r(0), c(0), lid(0), rid(0) {}

    node(int _l, int _r)
        : l(_l), r(_r), c(0), lid(0), rid(0) {}
} tr[N << 7];

inline void pushup(int u) {
    tr[u].c = tr[tr[u].lid].c + tr[tr[u].rid].c;
}

int build(int l, int r) {
    int p = ++cnt;
    tr[p] = node(l, r);
    if (l == r) return p;
    int mid = l + r >> 1;
    tr[p].lid = build(l, mid);
    tr[p].rid = build(mid + 1, r);
    return p;
}

int insert(int p, int x, int v) {
    int q = ++cnt;
    tr[q] = tr[p];
    if (tr[q].l == tr[q].r) {
        tr[q].c += v;
        return q;
    }
    int mid = tr[q].l + tr[q].r >> 1;
    if (x <= mid) {
        tr[q].lid = insert(tr[p].lid, x, v);
    } else {
        tr[q].rid = insert(tr[p].rid, x, v);
    }
    pushup(q);
    return q;
}

int query(int u, int x) {
    if (tr[u].l == tr[u].r) return tr[u].c;
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) return tr[tr[u].rid].c + query(tr[u].lid, x);
    return query(tr[u].rid, x);
}
