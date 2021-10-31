#include <bits/stdc++.h>

using namespace std;

int n, m, s, u, v, w, dist[200005];
vector<pair<int, int>> g[200005];
bool st[200005];

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        int tw = t.second;
        int td = t.first;
        if (st[tw]) continue;
        for (auto i : g[tw]) {
            int j = i.first;
            if (dist[j] > td + i.second) {
                dist[j] = td + i.second;
                q.push(make_pair(dist[j], j));
            }
        }
        st[tw] = true;
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
    }
    dijkstra();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << endl;
    return 0;
}
