#include <iostream>
#include <algorithm>
#include <compare>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1505;

int n, a[N], f[N][3];
std::vector<int> g[N];

void dfs(int u, int fa) {
    f[u][2] = a[u];

    for (int v : g[u]) {
        if (v == fa) continue;

        dfs(v, u);

        f[u][0] += std::min(f[v][1], f[v][2]);
        f[u][2] += std::min({f[v][0], f[v][1], f[v][2]});
    }

    f[u][1] = std::numeric_limits<int>::max();

    for (int v : g[u]) {
        if (v == fa) continue;

        f[u][1] = std::min(f[u][1], f[u][0] - std::min(f[v][1], f[v][2]) + f[v][2]);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, u, v, m; i <= n; i++) {
        cin >> u >> a[u] >> m;

        while (m--) {
            cin >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
    }

    dfs(1, 0);

    cout << std::min(f[1][1], f[1][2]) << endl;

    return 0;
}
