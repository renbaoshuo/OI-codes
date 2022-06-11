#include <iostream>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

int n, k, fa[N], siz[N];
long long f[N][N];
std::vector<std::pair<int, int>> g[N];

void dfs(int u, int fa) {
    siz[u] = 1;
    f[u][0] = f[u][1] = 0;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa) continue;

        dfs(v, u);

        siz[u] += siz[v];

        for (int i = std::min(k, siz[u]); ~i; i--) {
            if (~f[u][i]) {
                f[u][i] += f[v][0] + 1ll * siz[v] * (n - k - siz[v]) * w;
            }

            for (int j = std::min(i, siz[v]); j; j--) {
                if (~f[u][i - j]) {
                    f[u][i] = std::max(f[u][i], f[u][i - j] + f[v][j] + 1ll * (j * (k - j) + (siz[v] - j) * (n - k - siz[v] + j)) * w);
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    k = std::max(k, n - k);

    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;

        g[u].push_back(std::make_pair(v, w));
        g[v].push_back(std::make_pair(u, w));
    }

    memset(f, 0xff, sizeof(f));

    dfs(1, 0);

    cout << f[1][k] << endl;

    return 0;
}
