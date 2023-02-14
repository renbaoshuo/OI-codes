#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1505,
          M = 5005;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n, m, dist[N], deg[N], cnt_in[N], cnt_out[N], ans[M];
std::vector<std::tuple<int, int, int>> g[N];
std::tuple<int, int, int, bool> edges[M];
bool vis[N];

void dijkstra(int s) {
    std::fill(std::begin(dist), std::end(dist), INF);
    std::fill(std::begin(vis), std::end(vis), false);

    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<>>
        q;

    q.emplace(0, s);
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (vis[u]) continue;

        for (auto e : g[u]) {
            int v, w;

            std::tie(v, w, std::ignore) = e;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;

                q.emplace(dist[v], v);
            }
        }

        vis[u] = true;
    }
}

void topo(int s) {
    std::fill(std::begin(deg), std::end(deg), 0);
    std::fill(std::begin(cnt_in), std::end(cnt_in), 0);
    std::fill(std::begin(cnt_out), std::end(cnt_out), 0);

    for (int i = 1; i <= m; i++) {
        if (std::get<3>(edges[i])) {
            deg[std::get<1>(edges[i])]++;
        }
    }

    std::queue<int> q;
    std::vector<int> v;

    cnt_in[s] = 1;
    q.emplace(s);

    while (!q.empty()) {
        int u = q.front();

        v.emplace_back(u);
        q.pop();

        for (auto e : g[u]) {
            int v, w, id;

            std::tie(v, w, id) = e;

            if (std::get<3>(edges[id])) {
                cnt_in[v] = (static_cast<long long>(cnt_in[v]) + cnt_in[u]) % mod;

                if (--deg[v] == 0) {
                    q.emplace(v);
                }
            }
        }
    }

    std::for_each(v.rbegin(), v.rend(), [&](int u) {
        for (auto e : g[u]) {
            int v, w, id;

            std::tie(v, w, id) = e;

            if (std::get<3>(edges[id])) {
                cnt_out[u] = (static_cast<long long>(cnt_out[u]) + cnt_out[v]) % mod;
            }
        }

        cnt_out[u] = (cnt_out[u] + 1) % mod;
    });
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w, i);
        edges[i] = {u, v, w, false};
    }

    for (int i = 1; i <= n; i++) {
        dijkstra(i);

        std::for_each(
            std::begin(edges) + 1,
            std::begin(edges) + m + 1,
            [&](auto &e) {
                int u = std::get<0>(e),
                    v = std::get<1>(e),
                    w = std::get<2>(e);

                std::get<3>(e) = dist[u] + w == dist[v];
            });

        topo(i);

        for (int j = 1; j <= m; j++) {
            int u, v;
            bool is_short;

            std::tie(u, v, std::ignore, is_short) = edges[j];

            if (is_short) {
                ans[j] = (static_cast<long long>(ans[j])
                          + static_cast<long long>(cnt_in[u]) * cnt_out[v] % mod)
                       % mod;
            }
        }
    }

    std::copy_n(std::begin(ans) + 1, m, std::ostream_iterator<int>(cout, "\n"));

    return 0;
}
