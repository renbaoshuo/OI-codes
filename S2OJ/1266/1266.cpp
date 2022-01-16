#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

int n, m, x, h[N], nh[N];
std::vector<std::pair<int, long long>> g[N];

// Dijkstra - Shortest Path
long long dist[N];
bool vis[N];
void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> q;
    q.push(std::make_pair(0, 1));
    nh[1] = x;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto e : g[u]) {
            int v = e.first;
            long long w = e.second;
            if (nh[u] - w > h[v]) {  // 到达点的高度大于树顶高度
                if (dist[v] > dist[u] + nh[u] - h[v]) {
                    dist[v] = dist[u] + nh[u] - h[v];
                    nh[v] = h[v];
                    q.push(std::make_pair(dist[v], v));
                }
            } else if (nh[u] - w < 0) {  // 飞行中途会落地
                if (dist[v] > dist[u] + w - nh[u] + w) {
                    dist[v] = dist[u] + w - nh[u] + w;
                    nh[v] = 0;
                    q.push(std::make_pair(dist[v], v));
                }
            } else if (dist[v] > dist[u] + w) {  // 其他情况
                dist[v] = dist[u] + w;
                nh[v] = nh[u] - w;
                q.push(std::make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        // 保证飞行中途不落地
        if (w <= h[u]) g[u].push_back(std::make_pair(v, w));
        if (w <= h[v]) g[v].push_back(std::make_pair(u, w));
    }
    dijkstra();
    cout << (dist[n] == 0x3f3f3f3f3f3f3f3f ? -1 : dist[n] + h[n] - nh[n]) << endl;
    return 0;
}
