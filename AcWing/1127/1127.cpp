#include <bits/stdc++.h>

using namespace std;

int n, p, c, a[505], dist[805], u, v, w, ans = 0x3f3f3f3f;
bool vis[805];
vector<pair<int, int>> g[805];

int dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0x00, sizeof(vis));
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (vis[t.second]) continue;
        for (auto i : g[t.second]) {
            if (dist[i.first] > t.first + i.second) {
                dist[i.first] = t.first + i.second;
                q.push(make_pair(dist[i.first], i.first));
            }
        }
        vis[t.second] = true;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[a[i]] == 0x3f3f3f3f) return 0x3f3f3f3f;
        sum += dist[a[i]];
    }
    return sum;
}

int main() {
    cin >> n >> p >> c;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= c; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    for (int i = 1; i <= p; i++) {
        ans = min(ans, dijkstra(i));
    }
    cout << ans << endl;
    return 0;
}
