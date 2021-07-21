#include <bits/stdc++.h>

using namespace std;

struct node {
    int u, v, w;
} g[10005];

int n, m, k, dist[505], backup[505];

void bellman_ford() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 1; i <= k; i++) {
        memcpy(backup, dist, sizeof(dist));
        for (int j = 1; j <= m; j++) {
            dist[g[j].v] = min(dist[g[j].v], backup[g[j].u] + g[j].w);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> g[i].u >> g[i].v >> g[i].w;
    }
    bellman_ford();
    if (dist[n] > 0x1f1f1f1f) {
        cout << "impossible" << endl;
    } else {
        cout << dist[n] << endl;
    }
    return 0;
}
