#include <iostream>
#include <algorithm>
#include <functional>
#include <limits>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

int n, d[N];
long long f[N][2];
std::vector<std::pair<int, int>> g[N];

void dfs(int u, int fa) {
    std::vector<long long> weights;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa) continue;

        dfs(v, u);
        weights.push_back(f[v][0] + w - f[v][1]);

        f[u][0] += f[v][1];
        f[u][1] += f[v][1];
    }

    std::sort(weights.begin(), weights.end(), std::greater<>());

    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] <= 0) break;
        if (i < d[u] - 1) f[u][0] += weights[i];
        if (i < d[u]) f[u][1] += weights[i];
    }

    if (!d[u]) f[u][0] = std::numeric_limits<int>::min();
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs(1, 0);

    cout << f[1][1] << endl;

    return 0;
}
