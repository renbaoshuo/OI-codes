#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e3 + 5;
const int INF = 0X3f3f3f3f;

int t, n, m, dist[N], cnt[N];
std::vector<std::pair<int, int>> g[N];
bool vis[N];

bool spfa() {
    std::fill_n(cnt, N, 0);
    std::fill_n(vis, N, false);
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
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n) return false;
                    vis[v] = true;
                    q.emplace(v);
                }
            }
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 1, u, v, w; i <= m; i++) {
            cin >> u >> v >> w;

            g[u].emplace_back(v, w);
            if (w >= 0) g[v].emplace_back(u, w);
        }

        cout << (!spfa() ? "YES" : "NO") << endl;

        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
    }

    return 0;
}
