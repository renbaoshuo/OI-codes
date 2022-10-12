#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

int n, m, cnt, father[N];
int dep[N], id[N], siz[N], fa[N], son[N], top[N], w[N];
std::tuple<int, int, bool, int> edges[N];
std::vector<std::pair<int, int>> g[N];

void dfs1(int u, int f) {
    fa[u] = father[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;

    for (auto e : g[u]) {
        int v = e.first,
            i = e.second;

        if (v == f) continue;

        id[v] = i;
        dfs1(v, u);
        siz[u] += siz[v];

        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}

void dfs2(int u, int t) {
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

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v, c; i <= m; i++) {
        cin >> u >> v >> c;

        if (c) {
            g[u].emplace_back(v, i);
            g[v].emplace_back(u, i);
        }

        edges[i] = std::make_tuple(u, v, c, 0);
    }

    dfs1(1, 1);
    dfs2(1, 1);

    for (int i = 1; i <= m; i++) {
        if (std::get<3>(edges[i])) continue;

        if (!std::get<2>(edges[i])) {
            int u = std::get<0>(edges[i]),
                v = std::get<1>(edges[i]),
                l = lca(u, v);
            std::vector<int> ids;

            while (dep[u] > dep[l]) {
                if (!std::get<3>(edges[id[u]])) {
                    ids.push_back(id[u]);
                }

                int t = father[u];
                father[u] = l;
                u = t;
            }

            while (dep[v] > dep[l]) {
                if (!std::get<3>(edges[id[v]])) {
                    ids.push_back(id[v]);
                }

                int t = father[v];
                father[v] = l;
                v = t;
            }

            std::sort(ids.begin(), ids.end());

            for (int id : ids) {
                std::get<3>(edges[id]) = ++cnt;
            }
        }

        std::get<3>(edges[i]) = ++cnt;
    }

    for (int i = 1; i <= m; i++) {
        cout << std::get<3>(edges[i]) << ' ';
    }

    cout << endl;

    return 0;
}
