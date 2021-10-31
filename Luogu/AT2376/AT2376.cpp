#include <bits/stdc++.h>

using namespace std;

int n, u, v;
vector<int> g[100005];
bool flag, vis[100005];

void dfs(int u, int f) {
    if (flag) return;
    for (int i : g[u]) {
        if (i != f) dfs(i, u);
    }
    if (!vis[u]) {
        if (f == -1 || vis[f]) {
            flag = true;
        } else {
            vis[f] = vis[u] = true;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << (flag ? "First" : "Second") << endl;
    return 0;
}
