#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int n, m, q, u, v, k, p, c[200005], fa[200005][25], w[2000005];
bool a[25][25];
vector<int> g[200005];

void dfs(int x, int f, int p) {
    if (!a[p][c[x]]) {
        fa[x][p] = x;
    } else {
        fa[x][p] = fa[f][p];
    }
    for (int i : g[x]) {
        if (i != f) dfs(i, x, p);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        dfs(1, 0, i);
    }
    for (int i = 1; i <= q; i++) {
        cin >> k >> p;
        for (int j = 1; j <= k; j++) {
            cin >> w[j];
        }
        for (int j = k; j > 0; j--) {
            p = fa[p][w[j]];
        }
        cout << !p << endl;
    }
    return 0;
}
