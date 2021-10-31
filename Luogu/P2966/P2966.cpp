#include <bits/stdc++.h>

using namespace std;

int n, m, q, u, v, w, s, t, f[255][255], ans[255][255];
pair<int, int> c[255];

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = i == j ? 0 : 0x3f3f3f3f;
            ans[i][j] = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        f[u][v] = min(f[u][v], w);
        f[v][u] = min(f[u][v], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[c[i].second][c[j].second] = min(f[c[i].second][c[j].second], f[c[i].second][c[k].second] + f[c[k].second][c[j].second]);
                ans[c[i].second][c[j].second] = min(ans[c[i].second][c[j].second], f[c[i].second][c[j].second] + max({c[i].first, c[j].first, c[k].first}));
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> s >> t;
        cout << ans[s][t] << endl;
    }
    return 0;
}
