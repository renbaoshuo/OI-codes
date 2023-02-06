#include <iostream>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 20;

int n, m;
long long f[N][N], ans;
bool map[N][N], vis[N];
std::vector<int> g[N];

void dfs(int u, int fa) {
    for (int i = 1; i <= n; i++) {
        if (vis[i]) f[u][i] = 1;
    }

    for (int v : g[u]) {
        if (v == fa) continue;

        dfs(v, u);

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) continue;

            long long t = f[u][i];

            for (int j = 1; j <= n; j++) {
                if (!vis[j] || !map[i][j]) continue;

                f[u][i] += t * f[v][j];
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        map[u][v] = map[v][u] = true;
    }

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for (int s = 0; s < 1 << n; s++) {
        memset(f, 0x00, sizeof(f));
        memset(vis, 0x00, sizeof(vis));

        for (int i = 1; i <= n; i++) {
            if ((s >> (i - 1)) & 1) vis[i] = true;
        }

        dfs(1, -1);

        long long sum = 0;

        for (int i = 1; i <= n; i++) {
            sum += f[1][i];
        }

        if ((n - __builtin_popcount(s)) & 1) {
            ans -= sum;
        } else {
            ans += sum;
        }
    }

    cout << ans << endl;

    return 0;
}
