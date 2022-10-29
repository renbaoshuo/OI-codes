#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, r, p, a[N];
std::vector<int> g[N];
int cnt, id[N], rid[N], fa[N], dep[N], siz[N], son[N], top[N];

struct node {
    int l, r;
    long long s, d;

    node()
        : l(0), r(0), s(0), d(0) {}

    node(int _l, int _r)
        : l(_l), r(_r), s(0), d(0) {}
} tr[N << 2];

inline void pushup(int u) {
    tr[u].s = (tr[u << 1].s + tr[u << 1 | 1].s) % p;
}

inline void pushdown(int u) {
    node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];

    left.s = (left.s + (left.r - left.l + 1) * root.d) % p;
    left.d = (left.d + root.d) % p;

    right.s = (right.s + (right.r - right.l + 1) * root.d) % p;
    right.d = (right.d + root.d) % p;

    root.d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) {
        tr[u].s = a[rid[l]] % p;
        return;
    }

    int mid = l + r >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(u);
}

void modify(int u, int l, int r, int d) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].s = (tr[u].s + (tr[u].r - tr[u].l + 1) * d) % p;
        tr[u].d = (tr[u].d + d) % p;
        return;
    }

    pushdown(u);

    int mid = tr[u].l + tr[u].r >> 1;

    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);

    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].s % p;
    pushdown(u);

    int mid = tr[u].l + tr[u].r >> 1;
    long long res = 0;

    if (l <= mid) res = (res + query(u << 1, l, r)) % p;
    if (r > mid) res = (res + query(u << 1 | 1, l, r)) % p;

    return res;
}

void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;

    for (int v : g[u]) {
        if (v == f) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}

void dfs2(int u, int t) {
    rid[id[u] = ++cnt] = u;
    top[u] = t;

    if (!son[u]) return;

    dfs2(son[u], t);

    for (int v : g[u]) {
        if (v == fa[u] || v == son[u]) continue;

        dfs2(v, v);
    }
}

void modify_path(int u, int v, int x) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        modify(1, id[top[u]], id[u], x);
        u = fa[top[u]];
    }

    if (dep[u] < dep[v]) std::swap(u, v);
    modify(1, id[v], id[u], x);
}

int query_path(int u, int v) {
    int res = 0;

    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        res = (res + query(1, id[top[u]], id[u])) % p;
        u = fa[top[u]];
    }

    if (dep[u] < dep[v]) std::swap(u, v);
    res = (res + query(1, id[v], id[u])) % p;

    return res;
}

void modify_tree(int u, int x) {
    modify(1, id[u], id[u] + siz[u] - 1, x);
}

int query_tree(int u) {
    return query(1, id[u], id[u] + siz[u] - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r >> p;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;

        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    dfs1(r, r);
    dfs2(r, r);
    build(1, 1, n);

    for (int i = 1; i <= m; i++) {
        int op;

        cin >> op;

        if (op == 1) {
            int x, y, z;

            cin >> x >> y >> z;

            modify_path(x, y, z);
        } else if (op == 2) {
            int x, y;

            cin >> x >> y;

            cout << query_path(x, y) << endl;
        } else if (op == 3) {
            int x, z;

            cin >> x >> z;

            modify_tree(x, z);
        } else {  // op == 4
            int x;

            cin >> x;

            cout << query_tree(x) << endl;
        }
    }

    return 0;
}
