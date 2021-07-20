#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, a, b;
long double z, dist[2005], g[2005][2005];
bool st[2005];

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        dist[i] = g[a][i];
    }
    dist[a] = 1;
    st[a] = true;
    for (int i = 1; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] < dist[j])) {
                t = j;
            }
        }
        st[t] = true;
        for (int j = 1; j <= n; j++) {
            dist[j] = max(dist[j], dist[t] * g[t][j]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        g[x][y] = g[y][x] = (100 - z) / 100.00;
    }
    cin >> a >> b;
    dijkstra();
    cout << fixed << setprecision(8) << 100 / dist[b] << endl;
    return 0;
}
