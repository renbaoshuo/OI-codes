#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505;

int n, m, e, tag[N], match[N], ans;
std::array<std::vector<int>, N> g;

bool dfs(int u, int t) {
    if (tag[u] == t) return false;

    tag[u] = t;

    for (int v : g[u]) {
        if (!match[v] || dfs(match[v], t)) {
            match[v] = u;
            return true;
        }
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> e;

    for (int i = 1, u, v; i <= e; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (dfs(i, i)) ans++;
    }

    cout << ans << endl;

    return 0;
}
