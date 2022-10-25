#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, k, a[N], c[N];
int cnt, id[N], fa[N], dep[N], siz[N], son[N], top[N];
std::vector<int> g[N], color[N];
std::set<int> ans;

void dfs1(int u, int f) {
    siz[u] = 1;
    fa[u] = f;
    dep[u] = dep[f] + 1;

    for (int v : g[u]) {
        if (v == f) continue;

        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int t) {
    id[u] = ++cnt;
    top[u] = t;

    if (!son[u]) return;
    dfs2(son[u], t);

    for (int v : g[u]) {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        u = fa[top[u]];
    }

    return dep[u] < dep[v] ? u : v;
}

void dfs3(int u, int f) {
    for (int v : g[u]) {
        if (v == f) continue;
        dfs3(v, u);
        c[u] += c[v];
    }

    if (c[u] == 1) ans.emplace(a[u]);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        color[a[i]].emplace_back(i);
    }

    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;

        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    dfs1(1, 0);
    dfs2(1, 1);

    for (int i = 1; i <= k; i++) {
        std::sort(color[i].begin(), color[i].end(), [&](int x, int y) -> bool { return id[x] < id[y]; });

        int u = 0, p = 0;

        for (int v : color[i]) {
            if (!u) {
                u = p = v;
                c[v]++;
            } else {
                p = lca(u, v);
                c[v]++, c[p]--;
            }
        }

        c[fa[p]]--;
    }

    dfs3(1, 0);

    cout << ans.size() << endl;

    for (int x : ans) {
        cout << x << ' ';
    }

    cout << endl;

    return 0;
}
