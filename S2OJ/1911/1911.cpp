#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

int n, m;
int id[N], rid[N], fa[N], dep[N], siz[N], son[N], top[N];
std::vector<int> g[N];

struct node {
    int l, r, m, d;

    node(const int &_l = 0, const int &_r = 0)
        : l(_l), r(_r), m(0), d(0) {}
} tr[N << 2];

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
    static int cnt = 0;

    rid[id[u] = ++cnt] = u;
    top[u] = t;

    if (son[u]) dfs2(son[u], t);

    for (int v : g[u]) {
        if (v == fa[u] || v == son[u]) continue;

        dfs2(v, v);
    }
}

void pushup(int u) {
    tr[u].m = std::max(tr[u << 1].m, tr[u << 1 | 1].m);
}

void pushdown(int u) {
    if (!tr[u].d) return;

    tr[u << 1].m += tr[u].d;
    tr[u << 1].d += tr[u].d;

    tr[u << 1 | 1].m += tr[u].d;
    tr[u << 1 | 1].d += tr[u].d;

    tr[u].d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) return;

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(u);
}

void modify(int u, int l, int r, int x) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].m += x;
        tr[u].d += x;

        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    pushdown(u);

    if (l <= mid) modify(u << 1, l, r, x);
    if (r > mid) modify(u << 1 | 1, l, r, x);

    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].m;

    int mid = (tr[u].l + tr[u].r) >> 1;

    pushdown(u);

    int res = 0;

    if (l <= mid) res = std::max(res, query(u << 1, l, r));
    if (r > mid) res = std::max(res, query(u << 1 | 1, l, r));

    return res;
}

void modify_tree(int u, int d) {
    modify(1, id[u], id[u] + siz[u] - 1, d);
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        u = fa[top[u]];
    }

    return dep[u] < dep[v] ? u : v;
}

int find(int u, int v) {
    while (top[u] != top[v]) {
        if (fa[top[v]] == u) return top[v];

        v = fa[top[v]];
    }

    return son[u];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;

        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);

    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;

        if (x != y) {
            int g = lca(x, y);

            if (dep[x] < dep[y]) std::swap(x, y);

            if (y == g) {  // x 在以 y 为根的子树内
                modify_tree(find(y, x), -1);
                modify_tree(x, 1);
            } else {
                modify_tree(1, -1);
                modify_tree(x, 1);
                modify_tree(y, 1);
            }
        }

        cout << i + query(1, 1, n) << endl;
    }

    return 0;
}
