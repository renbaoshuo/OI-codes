#include <iostream>
#include <algorithm>
#include <array>
#include <functional>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m;
long long s, alt[N];
std::vector<long long> alts;
std::vector<std::pair<int, long long>> g[N];
std::array<bool, N> vis;
std::array<long long, N> dist;

void dijkstra(long long limit) {
    std::fill(vis.begin(), vis.end(), false);
    std::fill(dist.begin(), dist.end(), std::numeric_limits<long long>::max() / 3);

    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

    q.emplace(0, 1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto e : g[u]) {
            int v = e.first;
            long long w = e.second;

            if (dist[v] > dist[u] + w && alt[v] - alt[u] <= limit) {
                dist[v] = dist[u] + w;
                q.emplace(dist[v], v);
            }
        }
    }
}

bool check(int x) {
    dijkstra(alts[x]);

    return dist[n] <= s;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;

    for (int i = 1; i <= n; i++) {
        cin >> alt[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        long long w;

        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        alts.emplace_back(alt[v] - alt[u]);

        g[v].emplace_back(u, w);
        alts.emplace_back(alt[u] - alt[v]);
    }

    std::sort(alts.begin(), alts.end());
    alts.erase(std::unique(alts.begin(), alts.end()), alts.end());

    int l = 0,
        r = alts.size() - 1,
        res = alts.size();

    while (l <= r) {
        int mid = l + r >> 1;

        if (check(mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    if (res == alts.size()) {
        cout << "NO" << endl;
    } else {
        cout << alts[res] << endl;
    }

    return 0;
}
