#include <bits/stdc++.h>

using namespace std;

int f, n, m, w, u, v, t, dist[505], cnt[505];
vector<pair<int, int>> g[505];
bool vis[505];

bool spfa() {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0x00, sizeof(vis));
    memset(cnt, 0x00, sizeof(cnt));
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        vis[i] = true;
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        vis[t] = false;
        for (auto i : g[t]) {
            if (dist[i.first] > dist[t] + i.second) {
                dist[i.first] = dist[t] + i.second;
                cnt[i.first] = cnt[t] + 1;
                if (cnt[i.first] >= n) return true;
                if (!vis[i.first]) {
                    q.push(i.first);
                    vis[i.first] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> f;
    while (f--) {
        cin >> n >> m >> w;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            cin >> u >> v >> t;
            g[u].push_back(make_pair(v, t));
            g[v].push_back(make_pair(u, t));
        }
        for (int i = 1; i <= w; i++) {
            cin >> u >> v >> t;
            g[u].push_back(make_pair(v, -t));
        }
        cout << (spfa() ? "YES" : "NO") << endl;
    }
    return 0;
}
