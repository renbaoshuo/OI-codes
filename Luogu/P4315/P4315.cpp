#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

int n, u, v, w, k, a[N];
std::string op;
std::pair<int, int> t[N];
std::vector<int> g[N];

// Heavy Path Decomposition
int cnt, b[N], id[N], fa[N], dep[N], siz[N], son[N], top[N];
void dfs1(int, int);
void dfs2(int, int);
void modify_path(int, int, int);
void change_path(int, int, int);
int query_path(int, int);

// Segment Tree
void pushup(int);
void pushdown(int);
void build(int, int, int);
void modify(int, int, int, int);
void change(int, int, int, int);
int query(int, int, int);

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> t[i].first >> t[i].second >> a[i];
        g[t[i].first].push_back(t[i].second);
        g[t[i].second].push_back(t[i].first);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    for (int i = 1; i < n; i++) {
        if (dep[t[i].first] < dep[t[i].second]) std::swap(t[i].first, t[i].second);
        modify(1, id[t[i].first], id[t[i].first], a[i]);
    }
    while (cin >> op, op != "Stop") {
        if (op == "Change") {
            cin >> k >> w;
            change(1, id[t[k].first], id[t[k].first], w);
        } else if (op == "Cover") {
            cin >> u >> v >> w;
            change_path(u, v, w);
        } else if (op == "Add") {
            cin >> u >> v >> w;
            modify_path(u, v, w);
        } else {
            cin >> u >> v;
            cout << query_path(u, v) << endl;
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

void modify_path(int u, int v, int d) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        modify(1, id[top[u]], id[u], d);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    modify(1, id[son[v]], id[u], d);
}

void change_path(int u, int v, int d) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        change(1, id[top[u]], id[u], d);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    change(1, id[son[v]], id[u], d);
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

// == Segment Tree ===

struct node {
    int l, r, m, da, dc;

    node()
        : l(0),
          r(0),
          m(0),
          da(0),
          dc(-1) {}

    node(int _l, int _r)
        : l(_l),
          r(_r),
          m(0),
          da(0),
          dc(-1) {}
} tr[N << 2];

inline void pushup(int u) {
    tr[u].m = std::max(tr[u << 1].m, tr[u << 1 | 1].m);
}

inline void pushdown(int u) {
    node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.dc != -1) {
        left.m = right.m = root.dc;
        left.da = right.da = 0;
        left.dc = right.dc = root.dc;
        root.dc = -1;
    }
    left.m += root.da;
    left.da += root.da;
    right.m += root.da;
    right.da += root.da;
    root.da = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].m = b[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int d) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].m += d;
        tr[u].da += d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);
    pushup(u);
}

void change(int u, int l, int r, int d) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].m = d;
        tr[u].da = 0;
        tr[u].dc = d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) change(u << 1, l, r, d);
    if (r > mid) change(u << 1 | 1, l, r, d);
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].m;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (l <= mid) res = std::max(res, query(u << 1, l, r));
    if (r > mid) res = std::max(res, query(u << 1 | 1, l, r));
    return res;
}
