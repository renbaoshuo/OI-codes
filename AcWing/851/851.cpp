#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, w, dist[100005];
vector<pair<int, int>> g[100005];

void spfa() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto i : g[t]) {
            if (dist[i.first] > dist[t] + i.second) {
                dist[i.first] = dist[t] + i.second;
                q.push(i.first);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
    }
    spfa();
    if (dist[n] == 0x3f3f3f3f) {
        cout << "impossible" << endl;
    } else {
        cout << dist[n] << endl;
    }
    return 0;
}
