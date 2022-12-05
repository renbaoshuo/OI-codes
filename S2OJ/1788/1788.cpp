#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e4 + 5,
          K = 11;
const int INF = 0x3f3f3f3f;

int n, m, d, f[1 << K][N], f1[1 << K];
std::vector<std::pair<int, int>> g[N];

int steiner(int s) {
    int k = 0;

    memset(f, 0x3f, sizeof(f));

    for (int i = 1; i <= d; i++) {
        std::queue<int> q;

        if (s & (1 << (i - 1))) {
            f[1 << k++][i] = 0;
            f[1 << k++][n - i + 1] = 0;
        }
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

    int res = INF;

    for (int i = 1; i <= n; i++) {
        res = std::min(res, f[(1 << k) - 1][i]);
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> d;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    memset(f1, 0x3f, sizeof(f1));

    f1[0] = 0;

    for (int s = 1; s < 1 << d; s++) {
        for (int t = s; t; t = (t - 1) & s) {
            f1[s] = std::min(f1[s], f1[s ^ t] + steiner(t));
        }
    }

    cout << (f1[(1 << d) - 1] == INF ? -1 : f1[(1 << d) - 1]) << endl;

    return 0;
}
