#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105,
          K = 12;
const int INF = 0x3f3f3f3f;

int n, m, k, a[K], f[1 << K][N], ans = INF;
std::vector<std::pair<int, int>> g[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    memset(f, 0x3f, sizeof(f));

    for (int i = 1; i <= k; i++) {
        cin >> a[i];

        f[1 << (i - 1)][a[i]] = 0;
    }

    for (int s = 0; s < 1 << k; s++) {
        std::queue<int> q;
        std::vector<bool> vis(n + 1);

        for (int i = 1; i <= n; i++) {
            for (int t = s & (s - 1); t; t = (t - 1) & s) {
                f[s][i] = std::min(f[s][i], f[t][i] + f[s ^ t][i]);
            }

            if (f[s][i] != INF) {
                q.emplace(i);
                vis[i] = true;
            }
        }

        // SPFA
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            vis[u] = false;

            for (auto e : g[u]) {
                int v = e.first,
                    w = e.second;

                if (f[s][v] > f[s][u] + w) {
                    f[s][v] = f[s][u] + w;

                    if (!vis[v]) {
                        q.emplace(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        ans = std::min(ans, f[(1 << k) - 1][a[i]]);
    }

    cout << ans << endl;

    return 0;
}
