#include <iostream>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int INF = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n, m;

        cin >> n >> m;

        int s = 0, t = 1;
        std::vector<int> a(n + 1), pre(n + 1), head((m + 1) << 1, -1);
        std::vector<std::tuple<int, int, int>> edges;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        std::function<void(int, int, int)> add = [&](int u, int v, int w) -> void {
            edges.emplace_back(v, w, head[u]);
            head[u] = edges.size() - 1;
        };

        for (int i = 1, x, y; i <= m; i++) {
            cin >> x >> y;

            add(i << 1, i << 1 | 1, 1);
            add(i << 1 | 1, i << 1, 1);

            add(pre[x], i << 1, pre[x] ? a[x] : 1);
            add(i << 1, pre[x], 0);
            pre[x] = i << 1;

            add(pre[y], i << 1 | 1, pre[y] ? a[y] : 1);
            add(i << 1 | 1, pre[y], 0);
            pre[y] = i << 1 | 1;
        }

        add(pre[1], t, a[1]);
        add(t, pre[1], 0);

        std::vector<int> dist((m + 1) << 1);

        std::function<bool()> bfs = [&]() -> bool {
            std::fill(dist.begin(), dist.end(), 0);

            std::queue<int> q;

            q.emplace(s);
            dist[s] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int i = head[u]; ~i; i = std::get<2>(edges[i])) {
                    int v = std::get<0>(edges[i]),
                        w = std::get<1>(edges[i]);

                    if (!dist[v] && w) {
                        dist[v] = dist[u] + 1;

                        if (v == t) return true;

                        q.emplace(v);
                    }
                }
            }

            return false;
        };

        std::function<int(int, int)> dinic = [&](int u, int limit) -> int {
            if (u == t) return limit;

            int flow = 0;

            for (int i = head[u]; ~i; i = std::get<2>(edges[i])) {
                int v = std::get<0>(edges[i]),
                    w = std::get<1>(edges[i]);

                if (dist[v] == dist[u] + 1 && w) {
                    int k = dinic(v, std::min(w, limit - flow));

                    if (!k) dist[v] = 0;

                    std::get<1>(edges[i]) -= k;
                    std::get<1>(edges[i ^ 1]) += k;
                    flow += k;
                }
            }

            return flow;
        };

        int res = 0;

        while (bfs()) {
            while (int flow = dinic(s, INF)) res += flow;
        }

        cout << res << endl;
    }

    return 0;
}
