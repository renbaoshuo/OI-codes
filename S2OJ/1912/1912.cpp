#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iterator>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 305,
          M = 3e4 + 5;
const int INF = 0x3f3f3f3f;

int n, m, k, x[M], y[M], z[M];
double p[N][N], f[N][N];
std::vector<std::pair<int, int>> g[N];
int dist[N];
bool vis[N];

void dijkstra(int s) {
    std::fill(std::begin(dist), std::end(dist), INF);
    std::fill(std::begin(vis), std::end(vis), false);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;

    q.emplace(0, s);
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (vis[u]) continue;

        for (auto e : g[u]) {
            int v = e.first,
                w = e.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;

                q.emplace(dist[v], v);
            }
        }

        vis[u] = true;
    }
}

void dfs(int u) {
    if (g[u].empty()) {
        std::copy(std::begin(p[u]), std::end(p[u]), std::begin(f[u]));

        return;
    }

    for (auto e : g[u]) {
        int v = e.first;

        dfs(v);

        for (int i = k; i; i--) {
            for (int j = 1; j <= i; j++) {
                f[u][i] = std::max(f[u][i], f[u][i - j] + f[v][j] / g[u].size());
            }
        }
    }

    for (int i = k; i; i--) {
        for (int j = 1; j <= i; j++) {
            f[u][i] = std::max(f[u][i], p[u][j] + f[u][i - j] * (1.0 - p[u][j]));
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> z[i];

        g[x[i]].emplace_back(y[i], z[i]);
        g[y[i]].emplace_back(x[i], z[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> p[i][j];
        }
    }

    dijkstra(1);
    std::fill(std::begin(g), std::end(g), std::vector<std::pair<int, int>>());

    for (int i = 1; i <= m; i++) {
        if (dist[x[i]] + z[i] == dist[y[i]]) {
            g[x[i]].emplace_back(y[i], 0);
        }

        if (dist[y[i]] + z[i] == dist[x[i]]) {
            g[y[i]].emplace_back(x[i], 0);
        }
    }

    dfs(1);

    cout << std::fixed << std::setprecision(6) << f[1][k] << endl;

    return 0;
}
