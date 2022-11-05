#include <iostream>
#include <algorithm>
#include <array>
#include <limits>
#include <queue>
#include <tuple>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5,
          Q = 3e5 + 5;

int n, q, k, l;
long long t;
std::tuple<int, int, int> edges[Q];
std::vector<int> ans;
std::array<std::vector<std::pair<int, long long>>, N> g;
std::array<bool, N> vis;
std::array<long long, N> dist;

void dijkstra() {
    std::fill(vis.begin(), vis.end(), false);
    std::fill(dist.begin(), dist.end(), std::numeric_limits<long long>::max() / 3);

    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> q;

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

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.emplace(dist[v], v);
            }
        }
    }
}

bool check(int l, int r) {
    std::fill(g.begin(), g.end(), std::vector<std::pair<int, long long>>());

    for (int i = l; i <= r; i++) {
        int u = std::get<0>(edges[i]),
            v = std::get<1>(edges[i]);
        long long w = std::get<2>(edges[i]);

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dijkstra();

    return dist[n] <= t;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q >> t;

    k = std::__lg(q) + 1;

    for (int i = 1; i <= q; i++) {
        cin >> std::get<0>(edges[i]) >> std::get<1>(edges[i]) >> std::get<2>(edges[i]);
    }

    while (l <= q) {
        bool flag = false;

        for (int i = 0; i <= k; i++) {
            int r = std::min(l + (1 << i), q);
            if (check(l, r)) {
                int ql = i ? l + (1 << i - 1) : 0,
                    qr = l + (1 << i),
                    res = qr;

                while (ql <= qr) {
                    int mid = (ql + qr) >> 1;
                    if (check(l, mid)) {
                        qr = mid - 1;
                        res = mid;
                    } else {
                        ql = mid + 1;
                    }
                }

                ans.emplace_back(res);
                l = res + 1;
                flag = true;

                break;
            }

            if (r == q) break;
        }

        if (!flag) break;
    }

    cout << ans.size() << endl;
    for (int x : ans) cout << x << ' ';
    cout << endl;

    return 0;
}
