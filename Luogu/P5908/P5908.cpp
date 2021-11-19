#include <bits/stdc++.h>

using namespace std;

int n, a, b, d, ans;
vector<int> g[100005];
bool vis[100005];

void dfs(int now, int dis) {
    vis[now] = true;
    if (dis == d) {
        return;
    }
    for (int i = 0; i < g[now].size(); i++) {
        if (!vis[g[now][i]]) {
            ans++;
            dfs(g[now][i], dis + 1);
        }
    }
    return;
}

int main() {
    memset(vis, 0x00, sizeof(vis));
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
