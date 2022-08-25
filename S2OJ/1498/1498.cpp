#include <iostream>
#include <cstring>
#include <deque>
#include <set>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1000005;

int n, m, id[N], last[N], dist[N];
bool vis[N];
std::set<int> cs;
std::vector<std::pair<int, int>> c[N], g[N];

void bfs() {
    memset(dist, 0x3f, sizeof(dist));

    std::deque<int> q;

    dist[1] = 0;
    q.emplace_back(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto e : g[u]) {
            int v = e.first,
                w = e.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;

                if (w) q.emplace_back(v);
                else q.emplace_front(v);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v, c; i <= m; i++) {
        cin >> u >> v >> c;

        ::c[c].emplace_back(u, v);
        cs.insert(c);
    }

    int cnt = n;
    for (int x : cs) {
        for (auto e : c[x]) {
            int u = e.first,
                v = e.second;

            if (last[u] != x) {
                last[u] = x;
                id[u] = ++cnt;
                g[u].emplace_back(id[u], 1);
                g[id[u]].emplace_back(u, 0);
            }

            if (last[v] != x) {
                last[v] = x;
                id[v] = ++cnt;
                g[v].emplace_back(id[v], 1);
                g[id[v]].emplace_back(v, 0);
            }

            g[id[u]].emplace_back(id[v], 0);
            g[id[v]].emplace_back(id[u], 0);
        }
    }

    bfs();

    cout << (dist[n] == 0x3f3f3f3f ? -1 : dist[n]) << endl;

    return 0;
}
