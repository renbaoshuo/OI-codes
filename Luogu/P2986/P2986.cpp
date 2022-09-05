#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, sum, root, c[N], siz[N], max_siz[N], dep[N];
long long ans;
std::vector<std::pair<int, int>> g[N];

void dfs1(int u, int f) {
    siz[u] = c[u];

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == f) continue;

        dfs1(v, u);

        siz[u] += siz[v];
        max_siz[u] = std::max(max_siz[u], siz[v]);
    }

    max_siz[u] = std::max(max_siz[u], sum - siz[u]);
}

void dfs2(int u, int f) {
    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == f) continue;

        dep[v] = dep[u] + w;
        dfs2(v, u);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];

        sum += c[i];
    }

    for (int i = 1, u, v, w; i <= n; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs1(1, 0);

    for (int i = 1; i <= n; i++) {
        if (!root || max_siz[i] < max_siz[root]) {
            root = i;
        }
    }

    dep[0] = -1;
    dfs2(root, 0);

    for (int i = 1; i <= n; i++) {
        ans += static_cast<long long>(c[i]) * dep[i];
    }

    cout << ans << endl;

    return 0;
}
