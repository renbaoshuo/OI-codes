#include <bits/stdc++.h>

using namespace std;

struct node {
    int v, l, c;

    node() {}
    node(int _v, int _l, int _c)
        : v(_v), l(_l), c(_c) {}
};

int n, m, x, u, v, l, c, tot, a[505], dist[505], ans = 0x3f3f3f3f;
vector<node> g[505];

void spfa(int x) {
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto i : g[u]) {
            if (dist[i.v] > dist[u] + i.l && i.c >= x) {
                dist[i.v] = dist[u] + i.l;
                q.push(i.v);
            }
        }
    }
}

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> l >> c;
        g[u].push_back(node(v, l, c));
        g[v].push_back(node(u, l, c));
        a[i] = c;
    }
    sort(a, a + m);
    for (int i = 0; i < m; i++) {
        spfa(a[i]);
        ans = min(ans, dist[n] + x / a[i]);
    }
    cout << ans << endl;
    return 0;
}
