#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, u, v, c, color[N];
char op;
vector<int> g[N];

// Link-cut Tree
int cnt, dep[N], id[N], siz[N], fa[N], son[N], top[N], w[N];
void dfs1(int, int);
void dfs2(int u, int t);
void modify_path(int, int, int);
int query_path(int, int);

// Segment Tree
void pushup(int);
void pushdown(int);
void build(int, int, int);
void modify(int, int, int, int);
int query_sum(int, int, int);
int query_color(int, int);

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    while (m--) {
        cin >> op >> u >> v;
        if (op == 'C') {
            cin >> c;
            modify_path(u, v, c);
        } else {
            cout << query_path(u, v) << endl;
        }
    }
    return 0;
}

// === Link-cut Tree ===

void dfs1(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u] = f;
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
    w[cnt] = color[u];
    top[u] = t;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int v : g[u]) {
        if (v == fa[u]) continue;
        if (v == son[u]) continue;
        dfs2(v, v);
    }
}

void modify_path(int u, int v, int c) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        modify(1, id[top[u]], id[u], c);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    modify(1, id[v], id[u], c);
}

int query_path(int u, int v) {
    int res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        res += query_sum(1, id[top[u]], id[u]);
        res -= (query_color(1, id[top[u]]) == query_color(1, id[fa[top[u]]]));
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    res += query_sum(1, id[v], id[u]);
    return res;
}

// === Segment Tree ===

struct node {
    int l, r, s, d, lc, rc;

    node()
        : l(0), r(0), s(0), d(0), lc(0), rc(0) {}
    node(int _l, int _r)
        : l(_l), r(_r), s(0), d(0), lc(0), rc(0) {}
} tr[N << 2];

inline void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s - (tr[u << 1].rc == tr[u << 1 | 1].lc);
    tr[u].lc = tr[u << 1].lc;
    tr[u].rc = tr[u << 1 | 1].rc;
}

inline void pushdown(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (!tr[u].d) return;
    left.d = right.d = root.d;
    left.lc = left.rc = right.lc = right.rc = root.d;
    left.s = right.s = 1;
    root.d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].lc = tr[u].rc = w[l];
        tr[u].s = 1;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int c) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].d = tr[u].lc = tr[u].rc = c;
        tr[u].s = 1;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, c);
    if (r > mid) modify(u << 1 | 1, l, r, c);
    pushup(u);
}

int query_sum(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    pushdown(u);
    if (l <= mid) res += query_sum(u << 1, l, r);
    if (r > mid) res += query_sum(u << 1 | 1, l, r);
    if (l <= mid && r > mid) res -= (tr[u << 1].rc == tr[u << 1 | 1].lc);
    return res;
}

int query_color(int u, int x) {
    if (tr[u].l == x && tr[u].r == x) {
        return tr[u].lc;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (x <= mid) return query_color(u << 1, x);
    return query_color(u << 1 | 1, x);
}
