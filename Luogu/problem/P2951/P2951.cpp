#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, dist[200005], ans1, ans2, ans3;
vector<int> g[200005];

void spfa() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (auto i : g[t]) {
            if (dist[i] > dist[t] + 1) {
                dist[i] = dist[t] + 1;
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    spfa();
    for (int i = 1; i <= n; i++) {
        if (ans2 < dist[i]) {
            ans2 = dist[i];
            ans1 = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans3 += dist[i] == ans2;
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
    return 0;
}
