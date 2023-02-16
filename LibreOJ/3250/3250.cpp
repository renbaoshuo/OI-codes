#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, c1[N], c2[N], c[N];
long long ans;
int id[N], rid[N], fa[N], dep[N], siz[N], son[N], top[N];
std::vector<std::pair<int, int>> g[N];

void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;

    for (auto e : g[u]) {
        int v = e.first;

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

    for (auto e : g[u]) {
        int v = e.first;

        if (v == fa[u] || v == son[u]) continue;

        dfs2(v, v);
    }
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        u = fa[top[u]];
    }

    return dep[u] < dep[v] ? u : v;
}

void dfs3(int u) {
    int fa_edge_id = 0;

    for (auto e : g[u]) {
        int v = e.first,
            id = e.second;

        if (v == fa[u]) {
            fa_edge_id = id;

            continue;
        }

        dfs3(v);

        c[u] += c[v];
    }

    ans += std::min<long long>(static_cast<long long>(c1[fa_edge_id]) * c[u], c2[fa_edge_id]);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v >> c1[i] >> c2[i];

        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    dfs1(1, 1);
    dfs2(1, 1);

    for (int i = 1; i < n; i++) {
        c[i]++, c[i + 1]++;
        c[lca(i, i + 1)] -= 2;
    }

    dfs3(1);

    cout << ans << endl;

    return 0;
}
