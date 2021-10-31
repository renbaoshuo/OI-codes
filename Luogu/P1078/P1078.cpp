#include <bits/stdc++.h>

using namespace std;

int n, k, m, s, t, u, v, w, c[105], g[105][105], f[105][105];

int main() {
    cin >> n >> k >> m >> s >> t;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        if (!g[c[u]][c[v]] && c[u] != c[v]) {
            f[u][v] = min(f[u][v], w);
        }
        if (!g[c[v]][c[u]] && c[v] != c[u]) {
            f[v][u] = min(f[v][u], w);
        }
    }
    if (c[s] == c[t]) {
        cout << -1 << endl;
        exit(0);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (k != i && k != j && i != j) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
    }
    cout << (f[s][t] == 0x3f3f3f3f ? -1 : f[s][t]) << endl;
    return 0;
}
