#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, a[100010];
vector<int> g[100010];

void dfs(int x, int d) {
    if (a[x]) {
        return;
    }
    a[x] = d;
    for (int i = 0; i < g[x].size(); i++) {
        dfs(g[x][i], d);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[v].push_back(u);
    }
    for (int i = n; i > 0; i--) {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
