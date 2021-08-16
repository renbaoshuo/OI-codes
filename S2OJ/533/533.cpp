#include <bits/stdc++.h>

using namespace std;

int n, m, opt, u, v, t, cnt;
vector<int> g[1000005];
bool vis[1000005];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto i : g[t]) {
            if (vis[i]) continue;
            q.push(i);
            vis[i] = true;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> opt;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[v].push_back(u);
    }
    cin >> t;
    bfs(t);
    for (int i = 1; i <= n; i++) {
        cnt += vis[i];
    }
    cout << cnt / __gcd(cnt, n) << '/' << n / __gcd(cnt, n) << endl;
    if (opt) {
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                cout << i << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
