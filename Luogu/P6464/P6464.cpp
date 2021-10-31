#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, w, g[105][105], f[105][105], sum, ans = 0x3f3f3f3f;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
                    f[k][l] = g[k][l];
                }
            }
            f[i][j] = f[j][i] = 0;
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
                    f[k][l] = min(f[k][l], f[k][i] + f[i][l]);
                }
            }
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
                    f[k][l] = min(f[k][l], f[k][j] + f[j][l]);
                }
            }
            sum = 0;
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l < k; l++) {
                    sum += f[k][l];
                }
            }
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}
