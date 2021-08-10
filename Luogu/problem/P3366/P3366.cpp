#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, w, g[5005][5005], dist[5005];
bool vis[5005];

int prim() {
    memset(dist, 0x3f, sizeof(dist));
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        if (i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
        if (i) res += dist[t];
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], g[t][j]);
        }
        vis[t] = true;
    }
    return res;
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    int ans = prim();
    if (ans == 0x3f3f3f3f) {
        cout << "orz" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
