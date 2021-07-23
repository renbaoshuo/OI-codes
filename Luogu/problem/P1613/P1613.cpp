#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, g[55][55];
bool f[55][55][55];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u][v] = f[u][v][0] = 1;
    }
    for (int p = 1; p <= 32; p++) {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (f[i][k][p - 1] && f[k][j][p - 1]) {
                        f[i][j][p] = true;
                        g[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    cout << g[1][n] << endl;
    return 0;
}
