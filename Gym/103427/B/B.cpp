#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, w[N << 1], cnt[2];
long long ans;
bool v[N << 1], vis[N], now[N];
std::vector<std::pair<int, int>> g[N];

void dfs(int u) {
    vis[u] = true;
    cnt[now[u]]++;

    for (auto e : g[u]) {
        int v = e.first,
            id = e.second;

        if (vis[v]) {
            if (now[u] ^ now[v] != ::v[id]) {
                cout << -1 << endl;

                exit(0);
            }

            continue;
        }

        now[v] = now[u] ^ ::v[id];
        dfs(v);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v >> w[i];

        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    for (int k = 0; k < 30; k++) {
        int res = 0;

        std::fill_n(vis, N, false);
        std::fill_n(now, N, false);

        for (int i = 1; i <= m; i++) {
            v[i] = (w[i] >> k) & 1;
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cnt[0] = cnt[1] = 0;

                dfs(i);

                res += std::min(cnt[0], cnt[1]);
            }
        }

        ans += static_cast<long long>(1 << k) * res;
    }

    cout << ans << endl;

    return 0;
}
