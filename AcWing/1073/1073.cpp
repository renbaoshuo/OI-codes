#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 10005,
          INF = 0x3f3f3f3f;

int n, d1[N], d2[N], p[N], up[N];
std::vector<std::pair<int, int>> g[N];

int dfs1(int u, int fa) {
    if (~fa && g[u].size() <= 1) return 0;

    d1[u] = d2[u] = -INF;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa) continue;

        int d = dfs1(v, u) + w;
        if (d >= d1[u]) {
            d2[u] = d1[u];
            d1[u] = d;
            p[u] = v;
        } else if (d > d2[u]) {
            d2[u] = d;
        }
    }

    return d1[u];
}

void dfs2(int u, int fa) {
    for (auto e : g[u]) {
        int v = e.first;
        int w = e.second;

        if (v == fa) continue;

        up[v] = std::max(up[u], p[u] == v ? d2[u] : d1[u]) + w;

        dfs2(v, u);
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;

        g[u].push_back(std::make_pair(v, w));
        g[v].push_back(std::make_pair(u, w));
    }

    dfs1(1, -1);
    dfs2(1, -1);

    int ans = INF;

    for (int i = 1; i <= n; i++) {
        ans = std::min(ans, std::max(d1[i], up[i]));
    }

    cout << ans << endl;

    return 0;
}
