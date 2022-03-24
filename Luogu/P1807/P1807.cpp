#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1505,
          INF = 0x3f3f3f3f;

int n, m, dist[N];
std::vector<std::pair<int, int>> g[N];

void spfa() {
    memset(dist, 0xff, sizeof(dist));

    std::queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto e : g[u]) {
            int v = e.first,
                w = e.second;

            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(std::make_pair(v, w));
    }
    spfa();
    cout << dist[n] << endl;
    return 0;
}
