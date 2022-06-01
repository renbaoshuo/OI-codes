#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 10005;

int n, m, k, s, t;
std::vector<std::pair<int, int>> g[N << 4];

int dist[N << 4];
bool vis[N << 4];

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0x00, sizeof(vis));

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

    q.push(std::make_pair(0, s));
    dist[s] = 0;

    while (!q.empty()) {
        auto t = q.top();
        q.pop();

        if (vis[t.second]) continue;

        for (auto e : g[t.second]) {
            int v = e.first,
                w = e.second;

            if (dist[v] > t.first + w) {
                dist[v] = t.first + w;

                q.push(std::make_pair(dist[v], v));
            }
        }

        vis[t.second] = true;
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m >> k >> s >> t;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        g[u].push_back(std::make_pair(v, w));
        g[v].push_back(std::make_pair(u, w));

        for (int j = 1; j <= k; j++) {
            g[u + (j - 1) * n].push_back(std::make_pair(v + j * n, 0));
            g[v + (j - 1) * n].push_back(std::make_pair(u + j * n, 0));
            g[u + j * n].push_back(std::make_pair(v + j * n, w));
            g[v + j * n].push_back(std::make_pair(u + j * n, w));
        }
    }

    for (int i = 1; i <= k; i++) {
        g[t + (i - 1) * n].push_back(std::make_pair(t + i * n, 0));
    }

    dijkstra();

    cout << dist[t + n * k] << endl;

    return 0;
}
