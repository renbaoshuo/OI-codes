#include <iostream>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

int n, m, c[N], cnt, dfn[N], siz[N], col_siz[N], tag[N], ans[N];
std::vector<int> g[N], col[N];
std::unordered_set<int> set;

void dfs1(int u, int f) {
    dfn[u] = ++cnt;
    siz[u] = 1;

    for (int v : g[u]) {
        if (v == f) continue;

        int t = col_siz[c[u]];

        dfs1(v, u);

        siz[u] += siz[v];

        t = siz[v] - (col_siz[c[u]] - t);

        col_siz[c[u]] += t;
        tag[v] += t;

        while (!col[c[u]].empty() && dfn[col[c[u]].back()] > dfn[u]) {
            tag[col[c[u]].back()] -= t;
            col[c[u]].pop_back();
        }
    }

    col_siz[c[u]]++;
    col[c[u]].emplace_back(u);
}

void dfs2(int u, int f) {
    ans[u] = ans[f] + tag[u];

    for (int v : g[u]) {
        if (v == f) continue;

        dfs2(v, u);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];

        m = std::max(m, c[i]);
        set.emplace(c[i]);
    }

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs1(1, 0);

    for (int x : set) {
        tag[1] += n - col_siz[x];

        for (int v : col[x]) {
            tag[v] -= n - col_siz[x];
        }
    }

    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << n * set.size() - ans[i] << endl;
    }

    return 0;
}
