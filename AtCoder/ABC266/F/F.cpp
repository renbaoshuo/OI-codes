#include <iostream>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, q, cnt, fa[N], color[N], root;
std::vector<int> g[N], circle;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool dfs1(int u, int f) {
    if (f != 0 && u == root) {
        return true;
    }

    for (int v : g[u]) {
        if (v == f) continue;

        if (dfs1(v, u)) {
            circle.emplace_back(u);

            return true;
        }
    }

    return false;
}

void dfs2(int u, int f, int c) {
    color[u] = c;

    for (int v : g[u]) {
        if (color[v]) continue;

        dfs2(v, u, c);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    std::iota(fa + 1, fa + 1 + n, 1);

    for (int i = 1, u, v; i <= n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);

        int x = find(u),
            y = find(v);

        if (x == y) {
            root = u;
        } else {
            fa[x] = y;
        }
    }

    dfs1(root, 0);

    for (int u : circle) {
        color[u] = ++cnt;
    }

    for (int u : circle) {
        for (int v : g[u]) {
            if (color[v]) continue;

            dfs2(v, u, color[u]);
        }
    }

    cin >> q;

    while (q--) {
        int x, y;

        cin >> x >> y;

        cout << (color[x] == color[y] ? "Yes" : "No") << endl;
    }

    return 0;
}
