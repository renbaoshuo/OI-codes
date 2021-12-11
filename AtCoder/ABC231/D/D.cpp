#include <cstdio>
#include <cstdlib>
#include <vector>

int n, m, a, b;
bool vis1[100005], vis2[100005];
std::vector<int> g[100005];

void dfs(int u, int f) {
    vis1[u] = 1;
    if (vis2[u]) {
        printf("No\n");
        exit(0);
    }
    vis2[u] = true;
    for (int v : g[u]) {
        if (v == f) continue;
        dfs(v, u);
    }
    vis2[u] = false;
}

int main() {
    scanf("%d%d", &n, &m);
    if (m >= n) {
        printf("No\n");
        exit(0);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis1[i])
            dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() > 2) {
            printf("No\n");
            exit(0);
        }
    }
    printf("Yes\n");
    return 0;
}
