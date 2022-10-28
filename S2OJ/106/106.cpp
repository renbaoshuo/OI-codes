#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, s, t, dist[N];
std::vector<std::pair<int, int>> g[N];
bool vis[N];

void dijkstra() {
    std::fill_n(dist, N, INF);

    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>>
        q;

    q.emplace(0, s);
    dist[s] = 0;

    while (!q.empty()) {
        auto u = q.top().second;
        q.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto e : g[u]) {
            int v = e.first,
                w = e.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s >> t;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dijkstra();

    cout << dist[t] << endl;

    return 0;
}
