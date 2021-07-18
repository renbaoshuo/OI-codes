#include <bits/stdc++.h>

using namespace std;

int n, m, s, x, y, z, g[10005][10005], dist[10005];
bool st[10005];

void diskstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
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
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    diskstra();
    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == 0x3f3f3f3f ? INT_MAX : dist[i]) << ' ';
    }
    cout << endl;
    return 0;
}
