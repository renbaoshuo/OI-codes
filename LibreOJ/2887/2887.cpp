#include <iostream>
#include <bitset>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 30001;

int n, m, l, s, t;
std::vector<std::pair<int, short>> g[N * 101];
int dist[N * 101];
std::bitset<N * 101> vis;

int spfa() {
    memset(dist, 0x3f, sizeof(dist));
    std::queue<int> q;

    dist[s] = 0;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        vis[u] = false;

        for (auto t : g[u]) {
            int v = t.first;
            short w = t.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;

                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    return dist[t] == 0x3f3f3f3f ? -1 : dist[t];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    l = std::min(static_cast<int>(std::sqrt(n)), 100);

    for (int i = 1, b, p; i <= m; i++) {
        cin >> b >> p;

        b++;

        if (i == 1) s = b;
        if (i == 2) t = b;

        if (p <= l) {
            g[b].emplace_back(p * n + b, 0);
        } else {
            for (int j = 1; b + j * p <= n; j++) {
                g[b].emplace_back(b + j * p, j);
            }

            for (int j = 1; b - j * p > 0; j++) {
                g[b].emplace_back(b - j * p, j);
            }
        }
    }

    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= n; j++) {
            g[i * n + j].emplace_back(j, 0);
        }

        for (int j = 1; j <= n - i; j++) {
            g[i * n + j].emplace_back(i * n + j + i, 1);
            g[i * n + j + i].emplace_back(i * n + j, 1);
        }
    }

    cout << spfa() << endl;

    return 0;
}
