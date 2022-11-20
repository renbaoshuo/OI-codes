#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, s, dep[N], fa[N][std::__lg(N) + 1];
std::vector<int> g[N];

void bfs(int s) {
    std::fill_n(dep, N, INF);

    std::queue<int> q;

    q.emplace(s);
    dep[0] = 0;
    dep[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dep[v] > dep[u] + 1) {
                dep[v] = dep[u] + 1;
                q.emplace(v);
                fa[v][0] = u;

                for (int k = 1; k <= std::__lg(n); k++) {
                    fa[v][k] = fa[fa[v][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);

    for (int k = std::__lg(n); k >= 0; k--) {
        if (dep[fa[x][k]] >= dep[y]) {
            x = fa[x][k];
        }
    }

    if (x == y) return x;

    for (int k = std::__lg(n); k >= 0; k--) {
        if (fa[x][k] != fa[y][k]) {
            x = fa[x][k];
            y = fa[y][k];
        }
    }

    return fa[x][0];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    bfs(s);

    while (m--) {
        int a, b;

        cin >> a >> b;

        cout << lca(a, b) << endl;
    }

    return 0;
}
