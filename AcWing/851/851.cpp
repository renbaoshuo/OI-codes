#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, dist[N];
std::vector<std::pair<int, int>> g[N];
bool vis[N];

void spfa() {
    std::fill_n(dist, N, INF);

    std::queue<int> q;

    q.emplace(1);
    dist[1] = 0;
    vis[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        vis[u] = false;

        for (auto e : g[u]) {
            int v = e.first,
                w = e.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;

                if (!vis[v]) {
                    vis[v] = true;
                    q.emplace(v);
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
    }

    spfa();

    if (dist[n] == INF) {
        cout << "impossible" << endl;
    } else {
        cout << dist[n] << endl;
    }

    return 0;
}
