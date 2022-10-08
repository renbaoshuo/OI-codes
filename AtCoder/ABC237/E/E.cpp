#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, m, h[N];
long long dist[N], ans;
std::vector<std::pair<int, int>> g[N];
bool vis[N];

void dijkstra() {
    std::fill_n(dist, N, INF);

    std::priority_queue<
        std::pair<long long, int>,
        std::vector<std::pair<long long, int>>,
        std::greater<>>
        q;

    q.emplace(0, 1);
    dist[1] = 0;

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
        cin >> h[i];
    }

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].emplace_back(v, std::max(h[v] - h[u], 0));
        g[v].emplace_back(u, std::max(h[u] - h[v], 0));
    }

    dijkstra();

    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, static_cast<long long>(h[1]) - h[i] - dist[i]);
    }

    cout << ans << endl;

    return 0;
}
