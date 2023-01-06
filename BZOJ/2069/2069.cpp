#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int INF = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ans = INF;

    cin >> n >> m;

    int s = 0, t = n + 1, size = t + 1;
    std::vector<std::tuple<int, int, int, int>> edges(m);

    for (auto& e : edges) {
        cin >> std::get<0>(e) >> std::get<1>(e) >> std::get<2>(e) >> std::get<3>(e);
    }

    for (int k = 0; k <= std::__lg(n); k++) {
        std::vector<std::vector<std::pair<int, int>>> g(size);

        for (auto& e : edges) {
            int u, v, a, b;

            std::tie(u, v, a, b) = e;

            if (u == 1) {
                if (v & (1 << k)) {
                    g[s].emplace_back(v, a);
                    g[v].emplace_back(s, b);
                } else {
                    g[v].emplace_back(t, b);
                    g[t].emplace_back(v, a);
                }
            } else if (v == 1) {
                if (u & (1 << k)) {
                    g[s].emplace_back(u, b);
                    g[u].emplace_back(s, a);
                } else {
                    g[u].emplace_back(t, a);
                    g[t].emplace_back(u, b);
                }
            } else {
                g[u].emplace_back(v, a);
                g[v].emplace_back(u, b);
            }
        }

        std::function<int(int, int)> dijkstra = [&](int s, int t) -> int {
            std::vector<int> dist(size, INF);
            std::vector<bool> vis(size);
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;

            q.emplace(0, s);
            dist[s] = 0;

            while (!q.empty()) {
                int u = q.top().second;
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

            return dist[t];
        };

        ans = std::min({ans, dijkstra(s, t), dijkstra(t, s)});
    }

    cout << ans << endl;

    return 0;
}
