#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, s;
long long dist[N];
std::vector<std::pair<int, long long>> g[N];
bool vis[N];

void spfa() {
    std::fill_n(dist, N, std::numeric_limits<int>::max());

    std::queue<int> q;

    q.emplace(s);
    dist[s] = 0;
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        vis[u] = false;

        for (auto e : g[u]) {
            int v = e.first;
            long long w = e.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;

                if (!vis[v]) {
                    vis[v] = true;
                    q.emplace(v);
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
    }

    spfa();

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }

    cout << endl;

    return 0;
}
