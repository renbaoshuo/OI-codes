#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, w, dist1[1005], dist2[1005], ans;
vector<pair<int, int>> g1[1005], g2[1005];
bool st1[1005], st2[1005];

void dijkstra1() {
    memset(dist1, 0x3f, sizeof(dist1));
    dist1[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (st1[t.second]) continue;
        for (auto i : g1[t.second]) {
            if (dist1[i.first] > t.first + i.second) {
                dist1[i.first] = t.first + i.second;
                q.push(make_pair(dist1[i.first], i.first));
            }
        }
        st1[t.second] = true;
    }
}

void dijkstra2() {
    memset(dist2, 0x3f, sizeof(dist2));
    dist2[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (st2[t.second]) continue;
        for (auto i : g2[t.second]) {
            if (dist2[i.first] > t.first + i.second) {
                dist2[i.first] = t.first + i.second;
                q.push(make_pair(dist2[i.first], i.first));
            }
        }
        st2[t.second] = true;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g1[u].push_back(make_pair(v, w));
        g2[v].push_back(make_pair(u, w));
    }
    dijkstra1();
    dijkstra2();
    for (int i = 2; i <= n; i++) {
        ans += dist1[i] + dist2[i];
    }
    cout << ans << endl;
    return 0;
}
