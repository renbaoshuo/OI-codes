#include <bits/stdc++.h>

using namespace std;

int d, p, c, f, s, t, dist[505], x;

struct node {
    int u, v, w;
} g[1005];

int main() {
    cin >> d >> p >> c >> f >> s;
    for (int i = 1; i <= p; i++) {
        cin >> g[i].u >> g[i].v;
        g[i].w = -d;
    }
    for (int i = p + 1; i <= p + f; i++) {
        cin >> g[i].u >> g[i].v >> t;
        g[i].w = t - d;
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= p + f; j++) {
            dist[g[j].v] = min(dist[g[j].v], dist[g[j].u] + g[j].w);
        }
    }
    for (int i = 1; i <= p + f; i++) {
        if (dist[g[i].v] > dist[g[i].u] + g[i].w) {
            cout << -1 << endl;
            exit(0);
        }
    }
    dist[0] = 0x3f3f3f3f;
    for (int i = 1; i <= c; i++) {
        x = dist[i] < dist[x] ? i : x;
    }
    cout << d - dist[x] << endl;
    return 0;
}
