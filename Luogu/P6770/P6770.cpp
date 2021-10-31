#include <bits/stdc++.h>

using namespace std;

int f, p, c, m, u, v, w, x, dist[505];
bool vis[505];
vector<pair<int, int>> g[505];
priority_queue<int, vector<int>, greater<int>> ans;

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[1] = 0;
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
}

int main() {
    cin >> f >> p >> c >> m;
    for (int i = 1; i <= p; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    dijkstra();
    for (int i = 1; i <= c; i++) {
        cin >> x;
        if (dist[x] <= m) ans.push(i);
    }
    cout << ans.size() << endl;
    while (!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}
