#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int n, m, a[N], f[N];
int cnt, id[N], rid[N], fa[N], dep[N], siz[N], son[N], top[N];
std::vector<std::pair<int, int>> g[N];

struct node {
    int l, r, v, max, sum;

    node() = default;

    node(int _l, int _r)
        : l(_l), r(_r), v(0), max(0), sum(0) {}
} tr[N << 2];

void pushup(int u) {
    tr[u].max = std::max(tr[u << 1].max, tr[u << 1 | 1].max);
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) {
        tr[u].max = a[rid[l]];
        tr[u].sum = static_cast<long long>(tr[u].max) * f[rid[l]] % mod;

        return;
    }

    int mid = l + r >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(u);
}

void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == f) continue;

        a[v] = w;
        dfs1(v, u);
        siz[u] += siz[v];

        if (siz[son[u]] < siz[v]) son[u] = v;
    }

    ::f[u] = static_cast<long long>(siz[u]) * (n - siz[u]) % mod;
}

void dfs2(int u, int t) {
    rid[id[u] = ++cnt] = u;
    top[u] = t;

    if (!son[u]) return;

    dfs2(son[u], t);

    for (auto e : g[u]) {
        int v = e.first;

        if (v == fa[u]) continue;
        if (v == son[u]) continue;

        dfs2(v, v);
    }
}

void modify(int u, int l, int r) {
    if (tr[u].max <= 1) return;

    if (tr[u].l == tr[u].r) {
        tr[u].max = std::sqrt(tr[u].max);
        tr[u].sum = static_cast<long long>(tr[u].max) * f[rid[tr[u].l]] % mod;

        return;
    }

    int mid = tr[u].l + tr[u].r >> 1;

    if (l <= mid) modify(u << 1, l, r);
    if (r > mid) modify(u << 1 | 1, l, r);

    pushup(u);
}

void modify_path(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        modify(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }

    if (u == v) return;
    if (dep[u] < dep[v]) std::swap(u, v);
    modify(1, id[v] + 1, id[u]);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);

    cout << tr[1].sum << endl;

    while (m--) {
        int u, v;

        cin >> u >> v;

        modify_path(u, v);

        cout << tr[1].sum << endl;
    }

    return 0;
}
