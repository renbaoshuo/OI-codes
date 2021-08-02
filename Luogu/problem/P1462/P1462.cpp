#include <bits/stdc++.h>

using namespace std;

int n, m, u, v;
long long b, w, l, r, mid, ans, f[10005], dist[10005];
vector<pair<int, long long>> g[10005];
bool vis[10005];

bool check(int x) {
    if (f[1] > x) return false;
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0x00, sizeof(vis));
    priority_queue<pair<long long, int>> q;
    dist[1] = 0;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (vis[t.second]) continue;
        for (auto i : g[t.second]) {
            if (f[i.first] > x) continue;
            if (dist[t.second] + i.second < dist[i.first]) {
                dist[i.first] = dist[t.second] + i.second;
                q.push(make_pair(-dist[i.first], i.first));
                if (i.first == n) return dist[n] < b;
            }
        }
        vis[t.second] = true;
    }
    return false;
}

int main() {
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        r = max(r, f[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    l = 1;
    ans = -1;
    while (l <= r) {
        mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (ans == -1) {
        cout << "AFK" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
