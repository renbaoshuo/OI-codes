#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, w, d, a, b, f[105][105], g[105][105], dist[105];
bool st[105];

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[a] = 0;
    for (int i = 1; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
        st[t] = true;
    }
}

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
        g[u][v] = f[u][v];
        g[v][u] = f[v][u];
    }
    cin >> a >> b;
    dijkstra();
    cout << dist[b] << endl;
    return 0;
}
