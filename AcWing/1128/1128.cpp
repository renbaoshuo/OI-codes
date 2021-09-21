#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, w, dist[105], ans;
vector<pair<int, int>> g[105];
bool vis[105];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, 1));
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
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 0x3f3f3f3f) {
            cout << -1 << endl;
            exit(0);
        } else {
            ans = max(ans, dist[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
