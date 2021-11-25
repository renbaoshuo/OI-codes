#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, q, x, y, u, v, a[N];
string op;
vector<int> g[N];
int cnt, id[N], w[N], top[N], son[N], dep[N], fa[N], siz[N];

// Heavy Path Decomposition
void dfs1(int, int);
void dfs2(int, int);
int query_path_sum(int, int);
int query_path_max(int, int);

// Segment Tree
void pushup(int);
void build(int, int, int);
void modify(int, int, int);
int query_sum(int, int, int);
int query_max(int, int, int);

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    cin >> q;
    while (q--) {
        cin >> op >> u >> v;
        if (op == "CHANGE") {
            modify(1, id[u], v);
        } else if (op == "QMAX") {
            cout << query_path_max(u, v) << endl;
        } else if (op == "QSUM") {
            cout << query_path_sum(u, v) << endl;
        }
    }
    return 0;
}

// === Heavy Path Decomposition ===

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

int query_path_max(int u, int v) {
    int res = numeric_limits<int>::min();
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        res = max(res, query_max(1, id[top[u]], id[u]));
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    res = max(res, query_max(1, id[v], id[u]));
    return res;
}

int query_path_sum(int u, int v) {
    int sum = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        sum += query_sum(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    sum += query_sum(1, id[v], id[u]);
    return sum;
}

// === Segment Tree ===

struct node {
    int l, r, sum, max;

    node()
        : l(0), r(0), sum(0), max(numeric_limits<int>::min()) {}
    node(int _l, int _r)
        : l(_l), r(_r), sum(0), max(numeric_limits<int>::min()) {}
} tr[N << 2];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].sum = w[l];
        tr[u].max = w[r];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int d) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].sum = d;
        tr[u].max = d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) {
        modify(u << 1, x, d);
    } else {
        modify(u << 1 | 1, x, d);
    }
    pushup(u);
}

int query_sum(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].sum;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if (l <= mid) sum += query_sum(u << 1, l, r);
    if (r > mid) sum += query_sum(u << 1 | 1, l, r);
    return sum;
}

int query_max(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].max;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int res = numeric_limits<int>::min();
    if (l <= mid) res = max(res, query_max(u << 1, l, r));
    if (r > mid) res = max(res, query_max(u << 1 | 1, l, r));
    return res;
}
