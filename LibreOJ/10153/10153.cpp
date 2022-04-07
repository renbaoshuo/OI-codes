#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, q, l[N], r[N], a[N], f[N][N];
std::vector<std::pair<int, int>> g[N];

void dfs(int u, int fa) {
    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa) continue;
        dfs(v, u);

        for (int k = q; k; k--) {
            for (int j = k - 1; j >= 0; j--) {
                f[u][k] = std::max(f[u][k], w + f[u][k - j - 1] + f[v][j]);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;

        g[u].push_back(std::make_pair(v, w));
        g[v].push_back(std::make_pair(u, w));
    }

    dfs(1, -1);

    cout << f[1][q] << endl;

    return 0;
}
