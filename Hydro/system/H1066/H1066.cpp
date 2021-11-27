#include <bits/stdc++.h>

using namespace std;

int n, m, s, u, v, w;
long long dist[100005];
vector<pair<int, int>> g[100005];
bool st[100005];

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
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
