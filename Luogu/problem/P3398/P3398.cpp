#include <bits/stdc++.h>

using namespace std;

int head[100005], ver[200005], nex[200005], tot;
int fa[100005][30], dep[100005];

inline void addedge(int u, int v) {
    ver[tot] = v;
    nex[tot] = head[u];
    head[u] = tot++;
}

void dfs(int pre, int cur) {
    fa[cur][0] = pre;
    dep[cur] = dep[pre] + 1;
    for (int i = 1; i <= 25; i++) {
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    }
    for (int i = head[cur]; i != -1; i = nex[i]) {
        if (!dep[ver[i]]) {
            dfs(cur, ver[i]);
        }
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) {
        swap(u, v);
    }
    for (int i = 25; i > -1; i--) {
        if (dep[fa[v][i]] >= dep[u]) {
            v = fa[v][i];
        }
    }
    if (u == v) {
        return v;
    }
    for (int i = 25; i > -1; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int main() {
    int n, t, x, y, a, b, c, d;
    cin >> n >> t;
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
    }
    dfs(0, 1);
    while (t--) {
        cin >> a >> b >> c >> d;
        int x = lca(a, b), y = lca(c, d);
        if (dep[x] > dep[y]) {
            swap(x, y);
            swap(a, c);
            swap(b, d);
        }
        cout << (lca(x, y) == x && (lca(a, y) == y || lca(b, y) == y) ? "Y" : "N") << endl;
    }
    return 0;
}
