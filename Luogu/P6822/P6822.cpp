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

const int N = 1e5 + 5,
          M = 2e5 + 5;
const long long INF = 0x3f3f3f3f'3f3f3f3f;

int n, m, s, t;
std::vector<std::tuple<int, int, int>> g[N];
std::vector<std::pair<int, int>> g2[M << 1];
long long dist[M << 1];
bool vis[M << 1];

void dijkstra() {
    std::fill(std::begin(dist), std::end(dist), INF);
    std::fill(std::begin(vis), std::end(vis), false);

    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> q;

    q.emplace(0, s);
    dist[s] = 0;

    while (!q.empty()) {
        long long l;
        int u;

        std::tie(l, u) = q.top();

        q.pop();

        if (vis[u]) continue;

        for (auto e : g2[u]) {
            int v = e.first,
                w = e.second;

            if (dist[v] > l + w) {
                dist[v] = l + w;

                q.emplace(dist[v], v);
            }
        }

        vis[u] = true;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w, i << 1);
        g[v].emplace_back(u, w, i << 1 | 1);
    }

    s = 0, t = 2 * m + 2;

    for (int i = 1; i <= n; i++) {
        std::sort(g[i].begin(), g[i].end(), [](const std::tuple<int, int, int> &lhs, const std::tuple<int, int, int> &rhs) {
            return std::get<1>(lhs) < std::get<1>(rhs);
        });

        for (int j = 0; j < g[i].size(); j++) {
            int v, w, id;

            std::tie(v, w, id) = g[i][j];

            g2[id ^ 1].emplace_back(id, w);

            if (i == 1) {
                g2[s].emplace_back(id, w);
            }

            if (v == n) {
                g2[id].emplace_back(t, w);
            }

            if (j != 0) {
                int w2, id2;

                std::tie(std::ignore, w2, id2) = g[i][j - 1];

                g2[id2].emplace_back(id, w - w2);
                g2[id].emplace_back(id2, 0);
            }
        }
    }

    dijkstra();

    cout << dist[t] << endl;

    return 0;
}
