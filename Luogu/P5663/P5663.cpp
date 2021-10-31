#include <bits/stdc++.h>

using namespace std;

int n, m, q, u, v, a, l, dist[100005][2];
vector<pair<int, int>> g[100005];
bool flag;

void bfs() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1][0] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (auto i : g[t.first]) {
            if (dist[i.first][t.second ^ 1] == 0x3f3f3f3f) {
                dist[i.first][t.second ^ 1] = dist[t.first][t.second] + 1;
                q.push(make_pair(i.first, t.second ^ 1));
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(make_pair(v, 1));
        g[v].push_back(make_pair(u, 1));
        flag = flag || u == 1 || v == 1;
    }
    bfs();
    for (int i = 1; i <= q; i++) {
        cin >> a >> l;
        cout << (flag && l >= dist[a][l & 1] ? "Yes" : "No") << endl;
    }
    return 0;
}
