#include <bits/stdc++.h>

using namespace std;

int n, m, s, t, u, v, w, dist[2505];
vector<pair<int, int>> g[2505];
bool st[2505];

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (st[t.second]) continue;
        for (auto i : g[t.second]) {
            if (dist[i.first] > t.first + i.second) {
                dist[i.first] = t.first + i.second;
                q.push(make_pair(dist[i.first], i.first));
            }
        }
        st[t.second] = true;
    }
}

int main() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    dijkstra();
    cout << dist[t] << endl;
    return 0;
}
