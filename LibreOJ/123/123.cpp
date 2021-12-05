#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int n, m, fa[500005];
long long ans;
struct node {
    int u, v, w;

    bool operator<(const node x) const {
        return w < x.w;
    }
} g[500005];

int find(int x) {
    return fa[x] = fa[x] != x ? find(fa[x]) : fa[x];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> g[i].u >> g[i].v >> g[i].w;
    }
    std::sort(g, g + m);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        g[i].u = find(g[i].u);
        g[i].v = find(g[i].v);
        if (g[i].u != g[i].v) {
            fa[g[i].u] = g[i].v;
            ans += g[i].w;
        }
    }
    cout << ans << endl;
    return 0;
}
