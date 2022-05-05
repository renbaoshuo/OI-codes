#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, n, k, x, y, a[N], siz[N], dis[N], ans;
std::vector<int> g[N];

void dfs(int u, int fa) {
    for (int v : g[u]) {
        if (v == fa) continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
        siz[u] += siz[v];
        ans += !!siz[v];
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        ans = 0;

        cin >> n >> k >> x >> y;

        siz[y] = 1;

        for (int i = 1; i <= k; i++) {
            cin >> a[i];
            siz[a[i]] = 1;
        }

        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(x, -1);

        cout << ans * 2 - dis[y] << endl;

        for (int i = 1; i <= n; i++) {
            g[i].clear();
            dis[i] = siz[i] = 0;
        }
    }

    return 0;
}
