#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m, q, c[N << 1], p[N], ans[N << 1], lst[N];
bool vis[N];
std::vector<int> g[N << 1], circle;

int dfs1(int u) {
    if (vis[u]) return u;
    vis[u] = true;
    return dfs1(p[u]);
}

void dfs2(int u, int f, int d) {
    int x = lst[c[u]];
    ans[u] = std::min({ans[u], ans[f] + 1, d - x + 1});
    lst[c[u]] = d;
    for (int v : g[u]) {
        if (v == f) continue;
        dfs2(v, u, d + 1);
    }
    lst[c[u]] = x;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    int root = dfs1(1);
    std::fill_n(vis, N, false);

    for (int u = p[root]; u != root; u = p[u]) {
        circle.emplace_back(u);
    }
    circle.emplace_back(root);

    for (int x : circle) {
        vis[x] = true;
        c[x + n] = c[x];
    }

    g[p[root] + n].emplace_back(root);
    for (int i = 1; i < circle.size(); i++) {
        g[circle[i]].emplace_back(circle[i - 1]);
        g[circle[i] + n].emplace_back(circle[i - 1] + n);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] && vis[p[i]]) continue;
        g[p[i]].emplace_back(i);
    }

    std::fill_n(ans, N << 1, 0x3f3f3f3f);
    ans[root + n] = 1;
    dfs2(root + n, 0, 1);

    cin >> q;

    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }

    return 0;
}
