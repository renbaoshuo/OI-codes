#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, p, k, dist[N << 10];
std::vector<std::pair<int, int>> g[N << 10];
bool vis[N << 10];

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

    q.push(std::make_pair(0, 1));
    dist[1] = 0;

    while (!q.empty()) {
        auto t = q.top();
        q.pop();

        if (vis[t.second]) continue;

        for (auto e : g[t.second]) {
            int v = e.first,
                w = e.second;

            if (dist[v] > std::max(t.first, w)) {
                dist[v] = std::max(t.first, w);

                q.push(std::make_pair(dist[v], v));
            }
        }

        vis[t.second] = true;
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> p >> k;

    for (int i = 1, u, v, w; i <= p; i++) {
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

    for (int i = 0; i <= k; i++) {
        g[n * i].push_back(std::make_pair(n * i + n, 0));
    }

    dijkstra();

    cout << (dist[n * k + n] == 0x3f3f3f3f ? -1 : dist[n * k + n]) << endl;

    return 0;
}
