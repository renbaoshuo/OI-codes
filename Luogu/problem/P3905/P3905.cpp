#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, w, d, a, b, f[105][105], g[105][105];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = f[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = w;
        g[u][v] = g[v][u] = 0;
    }
    cin >> d;
    for (int i = 1; i <= d; i++) {
        cin >> u >> v;
        g[u][v] = g[v][u] = f[u][v];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    cin >> a >> b;
    cout << g[a][b] << endl;
    return 0;
}
