#include <iostream>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int t, n, k;
std::vector<int> top, g[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;

    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }

    top.push_back(u);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        top.clear();
        std::fill_n(g, N, std::vector<int>());
        std::fill_n(vis, N, false);

        int ans = 0;

        cin >> n >> k;

        for (int i = 2, x; i <= n; i++) {
            cin >> x;

            g[i].push_back(x);
            g[x].push_back(i);
        }

        dfs(1);

        std::fill_n(vis, N, false);

        for (int u : top) {
            if (k <= 1) break;

            if (vis[u]) continue;

            for (int v : g[u]) {
                if (vis[v]) continue;

                vis[u] = vis[v] = true;
                ans++;
                k -= 2;
            }
        }

        cout << ans + k << endl;
    }

    return 0;
}
