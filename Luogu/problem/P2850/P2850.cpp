#include <bits/stdc++.h>

using namespace std;

int t, n, m, w, u, v, p, g[505][505];

bool check() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
            if (g[i][i] < 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> t;
    while (t--) {
        memset(g, 0x3f, sizeof(g));
        cin >> n >> m >> w;
        for (int i = 1; i <= m; i++) {
            cin >> u >> v >> p;
            g[u][v] = g[v][u] = min(g[u][v], p);
        }
        for (int i = 1; i <= w; i++) {
            cin >> u >> v >> p;
            g[u][v] = min(g[u][v], -p);
        }
        cout << (check() ? "YES" : "NO") << endl;
    }
    return 0;
}
