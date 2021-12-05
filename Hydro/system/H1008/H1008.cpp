#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int n, q, u, v, fa[500005][20], dep[500005];
std::vector<int> g[500005];

void bfs(int root) {
    memset(dep, 0x3f, sizeof(dep));
    std::queue<int> q;
    dep[0] = 0;
    dep[root] = 1;
    q.push(root);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int v : g[t]) {
            if (dep[v] > dep[t] + 1) {
                dep[v] = dep[t] + 1;
                q.push(v);
                fa[v][0] = t;
                for (int k = 1; k < 20; k++) {
                    fa[v][k] = fa[fa[v][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) std::swap(a, b);
    for (int k = 19; k >= 0; k--) {
        if (dep[fa[a][k]] >= dep[b]) {
            a = fa[a][k];
        }
    }
    if (a == b) return a;
    for (int k = 19; k >= 0; k--) {
        if (fa[a][k] != fa[b][k]) {
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    while (q--) {
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}
