#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, s, t;
vector<pair<int, int>> d(1);
vector<pair<int, double>> g[105];
double dist[105];
bool st[105];

double dis(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e9;
    }
    dist[s] = 0.00;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    q.push(make_pair(0.00, s));
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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        d.push_back(make_pair(x, y));
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(make_pair(y, dis(d[x], d[y])));
        g[y].push_back(make_pair(x, dis(d[x], d[y])));
    }
    cin >> s >> t;
    dijkstra();
    cout << fixed << setprecision(2) << dist[t] << endl;
    return 0;
}