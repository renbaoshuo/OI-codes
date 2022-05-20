#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

int n, x, t, a, b, u[N], v[N], w[N];
std::string op;
std::vector<int> g[N];

// Heavy Path Decomposition
int cnt, id[N], fa[N], dep[N], son[N], siz[N], top[N];
void dfs1(int, int);
void dfs2(int, int);
int query_path(int, int);

// Segment Tree
void pushup(int);
void pushdown(int);
void build(int, int, int);
void change(int, int, int);
int query(int, int, int);

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u[i] >> v[i] >> w[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    for (int i = 1; i < n; i++) {
        if (dep[u[i]] < dep[v[i]]) std::swap(u[i], v[i]);
        change(1, id[u[i]], w[i]);
    }
    while (cin >> op, op != "DONE") {
        if (op == "CHANGE") {
            cin >> x >> t;
            change(1, id[u[x]], t);
        } else {
            cin >> a >> b;
            cout << (a == b ? 0 : query_path(a, b)) << endl;
        }
    }
    return 0;
}

// === Heavy Path Decomposition ===

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
    id[u] = ++cnt;
    top[u] = t;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int v : g[u]) {
        if (v == fa[u]) continue;
        if (v == son[u]) continue;
        dfs2(v, v);
    }
}

int query_path(int u, int v) {
    int res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        res = std::max(res, query(1, id[top[u]], id[u]));
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    res = std::max(res, query(1, id[son[v]], id[u]));
    return res;
}

// === Segment Tree ===

struct node {
    int l, r, m;

    node()
        : l(0), r(0), m(0) {}

    node(int _l, int _r)
        : l(_l), r(_r), m(0) {}
} tr[N << 2];

inline void pushup(int u) {
    tr[u].m = std::max(tr[u << 1].m, tr[u << 1 | 1].m);
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void change(int u, int x, int d) {
    if (tr[u].l == tr[u].r) {
        tr[u].m = d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) {
        change(u << 1, x, d);
    } else {
        change(u << 1 | 1, x, d);
    }
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].m;
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (l <= mid) res = std::max(res, query(u << 1, l, r));
    if (r > mid) res = std::max(res, query(u << 1 | 1, l, r));
    return res;
}
