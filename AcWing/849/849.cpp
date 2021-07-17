#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, z, g[505][505], dist[505];
bool st[505];

int diskstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++) {
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
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    cout << diskstra() << endl;
    return 0;
}
