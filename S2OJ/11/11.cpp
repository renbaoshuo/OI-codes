#include <bits/stdc++.h>

using namespace std;

int n, m, x, u, v, w, g[1005][1005], ans;

int main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, g[i][x] + g[x][i]);
    }
    cout << ans << endl;
    return 0;
}
