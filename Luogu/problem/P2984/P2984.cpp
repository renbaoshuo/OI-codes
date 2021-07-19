#include <bits/stdc++.h>

using namespace std;

int n, m, b, r, s, l, p, q, dist[50005];
vector<pair<int, int>> g[50005];
bool st[50005];

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[1] = 0;
    q.push(make_pair(0, 1));
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
    cin >> n >> m >> b;
    for (int i = 1; i <= m; i++) {
        cin >> r >> s >> l;
        g[r].push_back(make_pair(s, l));
        g[s].push_back(make_pair(r, l));
    }
    dijkstra();
    for (int i = 1; i <= b; i++) {
        cin >> p >> q;
        cout << dist[p] + dist[q] << endl;
    }
    return 0;
}
