#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int n, m, s, t, u, v, w, dist[2505];
vector<pair<int, int>> g[2505];
bool vis[2505];

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (vis[t.second]) continue;
        for (auto i : g[t.second]) {
            if (dist[i.first] > i.second + t.first) {
                dist[i.first] = i.second + t.first;
                q.push(make_pair(dist[i.first], i.first));
            }
        }
        vis[t.second] = true;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    dijkstra();
    cout << dist[t] << endl;
    return 0;
}
