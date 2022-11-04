#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, c[N], fa[N], siz[N], son[N], cnt[N], color[N];
long long ans[N], res;
std::vector<int> g[N];
std::vector<std::pair<int, int>> edges;

void add(int u) {
    res += color[c[u]] - 2 * cnt[c[u]]++ - 1;
}

void del(int u) {
    res -= color[c[u]] - 2 * --cnt[c[u]] - 1;
}

void add(int u, int f) {
    add(u);
    for (int v : g[u])
        if (v != f) add(v, u);
}

void del(int u, int f) {
    del(u);
    for (int v : g[u])
        if (v != f) del(v, u);
}

void dfs(int u, int f) {
    fa[u] = f;
    siz[u] = 1;

    for (int v : g[u]) {
        if (v == f) continue;

        dfs(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}

void dsu(int u, int f) {
    for (auto v : g[u]) {
        if (v == f || v == son[u]) continue;

        dsu(v, u);
        del(v, u);
    }
    if (son[u]) dsu(son[u], u);

    for (auto v : g[u]) {
        if (v == f || v == son[u]) continue;

        add(v, u);
    }

    add(u);
    ans[u] = res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];

        color[c[i]]++;
    }

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
        edges.emplace_back(u, v);
    }

    dfs(1, 1);
    dsu(1, 1);

    for (auto e : edges) {
        int u = e.first,
            v = e.second;

        cout << (fa[u] == v ? ans[u] : ans[v]) << ' ';
    }

    cout << endl;

    return 0;
}
