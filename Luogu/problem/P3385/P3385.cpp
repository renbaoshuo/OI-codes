#include <bits/stdc++.h>

using namespace std;

int t, n, m, u, v, w, cnt, dist[2005];
bool flag;

struct node {
    int u, v, w;

    node() {
        u = v = w = 0;
    }
    node(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
} g[6005];

int main() {
    cin >> t;
    while (t--) {
        cnt = 0;
        flag = false;
        memset(g, 0x00, sizeof(g));
        memset(dist, 0x3f, sizeof(dist));
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> u >> v >> w;
            g[++cnt] = node(u, v, w);
            if (w >= 0) g[++cnt] = node(v, u, w);
        }
        dist[1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= cnt; j++) {
                if (dist[g[j].u] == 0x3f3f3f3f) continue;
                dist[g[j].v] = min(dist[g[j].v], dist[g[j].u] + g[j].w);
            }
        }
        for (int i = 1; i <= cnt; i++) {
            if (dist[g[i].u] == 0x3f3f3f3f || dist[g[i].v] == 0x3f3f3f3f) continue;
            if (dist[g[i].v] > dist[g[i].u] + g[i].w) {
                flag = true;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
