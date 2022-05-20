#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

// Basic
int n, m, u, v, op, a[N];
std::vector<int> g[N];

// Heavy Path Decomposition
int cnt, w[N], id[N], fa[N], dep[N], son[N], siz[N], top[N];
void dfs1(int, int);
void dfs2(int, int);
void modify_path(int, int, long long);
void modify_tree(int, long long);
long long query_path(int, int);

// Segment Tree
void pushup(int);
void pushdown(int);
void build(int, int, int);
void modify(int, int, int, long long);
long long query(int, int, int);

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
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
        cin >> op >> u;
        if (op == 1) {
            cin >> v;
            modify_path(u, u, v);
        } else if (op == 2) {
            cin >> v;
            modify_tree(u, v);
        } else {
            cout << query_path(1, u) << endl;
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
    w[cnt] = a[u];
    top[u] = t;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int v : g[u]) {
        if (v == fa[u]) continue;
        if (v == son[u]) continue;
        dfs2(v, v);
    }
}

void modify_path(int u, int v, long long d) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        modify(1, id[top[u]], id[u], d);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    modify(1, id[v], id[u], d);
}

inline void modify_tree(int u, long long d) {
    modify(1, id[u], id[u] + siz[u] - 1, d);
}

long long query_path(int u, int v) {
    long long sum = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        sum += query(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    sum += query(1, id[v], id[u]);
    return sum;
}

// === Segment Tree ===

struct node {
    int l, r;
    long long s, d;

    node()
        : l(0), r(0), s(0), d(0) {}

    node(int _l, int _r)
        : l(_l), r(_r), s(0), d(0) {}
} tr[N << 2];

inline void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

inline void pushdown(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    left.s += (left.r - left.l + 1) * root.d;
    left.d += root.d;
    right.s += (right.r - right.l + 1) * root.d;
    right.d += root.d;
    root.d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = w[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, long long d) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].d += d;
        tr[u].s += (tr[u].r - tr[u].l + 1) * d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);
    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    long long sum = 0;
    pushdown(u);
    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}
