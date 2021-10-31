#include <bits/stdc++.h>

using namespace std;

struct node {
    int to, cost, limit;

    node() {
        to = cost = limit = 0;
    }
    node(int _to, int _cost, int _limit) {
        to = _to;
        cost = _cost;
        limit = _limit;
    }

    bool operator<(const node& b) const {
        return cost > b.cost;
    }
};

int n, m, a, b, c, f, limit[1005], dist[1005], ans;
vector<node> g[1005];
bool st[1005];

int dijkstra(int x) {
    memset(st, 0x00, sizeof(st));
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<node> q;
    q.push(node(1, 0, x));
    dist[1] = 0;
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (st[t.to]) continue;
        for (auto i : g[t.to]) {
            if (i.limit >= x && dist[i.to] > dist[t.to] + i.cost) {
                dist[i.to] = dist[t.to] + i.cost;
                q.push(node(i.to, dist[i.to], x));
            }
        }
        st[t.to] = true;
    }
    return dist[n];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c >> f;
        limit[i] = f;
        g[a].push_back(node(b, c, f));
        g[b].push_back(node(a, c, f));
    }
    for (int i = 1; i <= m; i++) {
        ans = max(ans, limit[i] * 1000000 / dijkstra(limit[i]));
    }
    cout << ans << endl;
    return 0;
}
