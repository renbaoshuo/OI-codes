#include <iostream>
#include <algorithm>
#include <array>
#include <functional>
#include <iterator>
#include <memory>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e4 + 5;
const long long INF = 0x3f3f3f3f'3f3f3f3f;

int n, m, k, s1, s2, t;
std::pair<int, int> limits[N];
std::array<std::shared_ptr<int>, N> w;
std::vector<std::pair<int, std::shared_ptr<int>>> g[N];
std::tuple<int, int, int, int> edges[N];
std::array<long long, N> dis1, dis2;
bool vis[N];

void dijkstra(std::array<long long, N> &dis, int s) {
    std::fill(std::begin(dis), std::end(dis), INF);
    std::fill(std::begin(vis), std::end(vis), false);

    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>>
        q;

    q.emplace(0, s);
    dis[s] = 0;

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto &e : g[u]) {
            int v = e.first,
                w = *e.second;

            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;

                q.emplace(dis[v], v);
            }
        }
    }
}

bool solve(int x) {
    bool flag = true;

    while (flag) {
        flag = false;

        dijkstra(dis1, s1);
        dijkstra(dis2, s2);

        for (int i = 1; i <= k; i++) {
            if (*w[i] == std::get<3>(edges[i]) && dis1[std::get<0>(edges[i])] < dis2[std::get<0>(edges[i])] + x) {
                *w[i] = std::get<2>(edges[i]);
                flag = true;
            }
        }
    }

    return dis1[t] < dis2[t] + x;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k >> s1 >> s2 >> t;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, std::make_shared<int>(w));
    }

    for (int i = 1, u, v, l, r; i <= k; i++) {
        cin >> u >> v >> l >> r;

        edges[i] = {u, v, l, r};
        w[i] = std::make_shared<int>(r);
        g[u].emplace_back(v, w[i]);
    }

    for (int i = 1; i <= k; i++) {
        dijkstra(dis1, s1);
        dijkstra(dis2, s2);

        if (dis1[std::get<0>(edges[i])] < dis2[std::get<0>(edges[i])]) {
            *w[i] = std::get<2>(edges[i]);
        }
    }

    if (solve(0)) {
        cout << "WIN" << endl;

        for (int i = 1; i <= k; i++) {
            cout << *w[i] << ' ';
        }

        cout << endl;
    } else if (solve(1)) {
        cout << "DRAW" << endl;

        for (int i = 1; i <= k; i++) {
            cout << *w[i] << ' ';
        }

        cout << endl;
    } else {
        cout << "LOSE" << endl;
    }

    return 0;
}
