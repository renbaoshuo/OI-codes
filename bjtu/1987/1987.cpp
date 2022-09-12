#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e4 + 5;

int n, m, cnt, cnt2;
std::vector<int> g[N];
bool vis[N], flag = true;

void dfs(int u) {
    cnt++;
    vis[u] = true;

    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int pre = cnt;
            dfs(i);

            if (cnt - pre > 1) cnt2++;
        }
    }

    cout << (cnt2 <= 1 ? "YES" : "NO") << endl;

    return 0;
}
