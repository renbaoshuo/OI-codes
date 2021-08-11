#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, w, dist[100005], cnt[100005];
vector<pair<int, int>> g[100005];

bool spfa() {
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto i : g[t]) {
            if (dist[i.first] > dist[t] + i.second) {
                dist[i.first] = dist[t] + i.second;
                cnt[i.first] = cnt[t] + 1;
                if (cnt[i.first] >= n) return true;
                q.push(i.first);
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
    }
    cout << (spfa() ? "Yes" : "No") << endl;
    return 0;
}
