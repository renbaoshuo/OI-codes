#include <bits/stdc++.h>

using namespace std;

int n, m, fa[5005], res, cnt;
struct node {
    int u, v, w;

    bool operator<(const node x) const {
        return w < x.w;
    }
} g[200005];

int find(int x) {
    return fa[x] = fa[x] != x ? find(fa[x]) : fa[x];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> g[i].u >> g[i].v >> g[i].w;
    }
    sort(g, g + m);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        g[i].u = find(g[i].u);
        g[i].v = find(g[i].v);
        if (g[i].u != g[i].v) {
            fa[g[i].u] = g[i].v;
            res += g[i].w;
            cnt++;
        }
    }
    if (cnt < n - 1) {
        cout << "orz" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
