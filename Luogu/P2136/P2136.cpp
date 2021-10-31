#include <bits/stdc++.h>

using namespace std;

int n, m, dist1[1005], dist2[1005], backup[1005];

struct node {
    int s, t, w;
} g[10005];

void bellman_ford1() {
    memset(dist1, 0x3f, sizeof(dist1));
    dist1[1] = 0;
    for (int i = 1; i <= n; i++) {
        memcpy(backup, dist1, sizeof(dist1));
        for (int j = 1; j <= m; j++) {
            dist1[g[j].t] = min(dist1[g[j].t], backup[g[j].s] + g[j].w);
        }
    }
}

void bellman_ford2() {
    memset(dist2, 0x3f, sizeof(dist2));
    dist2[n] = 0;
    for (int i = 1; i <= n; i++) {
        memcpy(backup, dist2, sizeof(dist2));
        for (int j = 1; j <= m; j++) {
            dist2[g[j].t] = min(dist2[g[j].t], backup[g[j].s] + g[j].w);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> g[i].s >> g[i].t >> g[i].w;
        g[i].w = -g[i].w;
    }
    bellman_ford1();
    for (int i = 1; i <= m; i++) {
        if (dist1[g[i].t] > dist1[g[i].s] + g[i].w) {
            cout << "Forever love" << endl;
            exit(0);
        }
    }
    bellman_ford2();
    cout << min(dist1[n], dist2[1]) << endl;
    return 0;
}
