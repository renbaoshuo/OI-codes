#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 100005;

int n, k, fa[N];
std::vector<int> g[N];
std::array<int[25], N> f1, f2;

void dfs1(int u) {
    for (int v : g[u]) {
        if (v == fa[u]) continue;

        fa[v] = u;
        dfs1(v);

        for (int i = 1; i <= k; i++) {
            f1[u][i] += f1[v][i - 1];
        }
    }
}

void dfs2(int u) {
    for (int v : g[u]) {
        if (v != fa[u]) dfs2(v);
    }

    for (int i = 1; i <= k; i++) {
        int cnt = 0, t = u;

        while (++cnt < i && fa[t]) {
            f1[u][i] += (f2[fa[t]][i - cnt] - f2[t][i - cnt - 1]);
            t = fa[t];
        }

        if (fa[t]) f1[u][i] += f2[fa[t]][0];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        f1[i][0] = x;
    }

    dfs1(1);
    f2 = f1;
    dfs2(1);

    for (int i = 1; i <= n; i++) {
        int sum = 0;

        for (int j = 0; j <= k; j++) {
            sum += f1[i][j];
        }

        cout << sum << endl;
    }

    return 0;
}
