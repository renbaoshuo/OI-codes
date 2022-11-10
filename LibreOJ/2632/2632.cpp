#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505;
const int INF = 0x3f3f3f3f;

int n, m, dist[N * N];
std::vector<std::pair<int, int>> g[N * N];
bool vis[N * N];

int id(int x, int y) {
    return x * (m + 1) + y;
}

void dijkstra() {
    std::fill_n(dist, N * N, INF);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

    q.emplace(0, id(0, 0));
    dist[id(0, 0)] = 0;

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
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;

            cin >> c;

            g[id(i, j)].emplace_back(id(i - 1, j - 1), c != '\\');
            g[id(i - 1, j - 1)].emplace_back(id(i, j), c != '\\');
            g[id(i, j - 1)].emplace_back(id(i - 1, j), c != '/');
            g[id(i - 1, j)].emplace_back(id(i, j - 1), c != '/');
        }
    }

    dijkstra();

    if (dist[id(n, m)] == INF) {
        cout << "NO SOLUTION" << endl;
    } else {
        cout << dist[id(n, m)] << endl;
    }

    return 0;
}
