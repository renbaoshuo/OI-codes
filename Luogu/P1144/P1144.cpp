#include <bits/stdc++.h>

using namespace std;

const int mod = 100003;

int n, m, x, y, depth[1000005], cnt[1000005];
vector<int> g[1000005];
bool vis[1000005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    queue<int> q;
    depth[1] = 0;
    cnt[1] = 1;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i : g[t]) {
            if (!vis[i]) {
                vis[i] = true;
                depth[i] = depth[t] + 1;
                q.push(i);
            }
            if (depth[i] == depth[t] + 1) {
                cnt[i] = (cnt[i] + cnt[t]) % mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] % mod << endl;
    }
    return 0;
}
