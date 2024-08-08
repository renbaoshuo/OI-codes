#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m;
long long ans;
std::vector<std::pair<int, long long>> g[N];
long long dep1[N]{-1}, dep2[N]{-1};

void dfs(int u, int f, int w, long long *dep) {
    dep[u] = dep[f] + w;

    for (auto [v, w] : g[u]) {
        if (v == f) continue;

        dfs(v, u, w, dep);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        long long w;

        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs(1, 0, 1, dep1);

    int a = std::max_element(dep1 + 1, dep1 + n + 1) - dep1;

    dfs(a, 0, 1, dep1);

    int b = std::max_element(dep1 + 1, dep1 + n + 1) - dep1;

    dfs(b, 0, 1, dep2);

    for (int i = 1; i <= n; i++) {
        if (i == a || i == b) continue;

        ans = std::max(ans, std::min(dep1[i], dep2[i]) + dep1[b]);
    }

    cout << ans << endl;

    return 0;
}
