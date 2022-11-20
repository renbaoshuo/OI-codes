#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5005;
const int INF = 0x3f3f3f3f;

int n, m, dist[N], cnt[N];
std::vector<std::pair<int, int>> g[N];

bool spfa() {
    std::fill_n(dist, N, INF);

    std::queue<int> q;

    q.emplace(0);
    dist[0] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto e : g[u]) {
            int v = e.first,
                w = e.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;

                if (cnt[v] > n) return false;

                q.emplace(v);
            }
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        g[v].emplace_back(u, w);
    }

    for (int i = 1; i <= n; i++) {
        g[0].emplace_back(i, 0);
    }

    if (spfa()) {
        for (int i = 1; i <= n; i++) {
            cout << dist[i] << ' ';
        }

        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
