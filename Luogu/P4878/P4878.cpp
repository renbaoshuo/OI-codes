#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;
const int INF = 0x3f3f3f3f;

int n, ml, md, cnt[N], dist[N];
std::vector<std::pair<int, int>> g[N];
bool vis[N];

bool spfa(int s) {
    std::fill(std::begin(cnt), std::end(cnt), 0);
    std::fill(std::begin(vis), std::end(vis), false);
    std::fill(std::begin(dist), std::end(dist), INF);

    std::queue<int> q;

    q.emplace(s);
    dist[s] = 0;
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        vis[u] = false;

        for (auto e : g[u]) {
            int v = e.first,
                w = e.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;

                if (!vis[v]) {
                    cnt[v] = cnt[u] + 1;

                    if (cnt[v] >= n) return false;

                    vis[v] = true;
                    q.emplace(v);
                }
            }
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> ml >> md;

    for (int i = 1; i <= n; i++) {
        g[0].emplace_back(i, 0);
    }

    for (int i = 2; i <= n; i++) {
        g[i].emplace_back(i - 1, 0);
    }

    for (int i = 1, a, b, c; i <= ml; i++) {
        cin >> a >> b >> c;

        g[a].emplace_back(b, c);
    }

    for (int i = 1, a, b, c; i <= md; i++) {
        cin >> a >> b >> c;

        g[b].emplace_back(a, -c);
    }

    if (spfa(0) && spfa(1)) {
        cout << (dist[n] == INF ? -2 : dist[n]) << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
