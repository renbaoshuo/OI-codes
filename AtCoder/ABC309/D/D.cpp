#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

int n1, n2, m, dist1[N], dist2[N];
bool vis[N];
std::vector<int> g[N];

void bfs(int s, int* dist) {
    std::queue<int> q;

    q.emplace(s);
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (vis[v]) continue;

            vis[v] = true;

            dist[v] = dist[u] + 1;
            q.emplace(v);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n1 >> n2 >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    bfs(1, dist1);
    bfs(n1 + n2, dist2);

    cout << *std::max_element(dist1 + 1, dist1 + 1 + n1)
                + *std::max_element(dist2 + n1 + 1, dist2 + n1 + n2 + 1) + 1
         << endl;

    return 0;
}
