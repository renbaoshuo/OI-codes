#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, dep[N];
std::vector<int> g[N];

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;

    for (int v : g[u]) {
        if (v == fa) continue;

        dfs(v, u);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(1, 0);

    int u = std::max_element(dep + 1, dep + n + 1) - dep;

    std::fill(std::begin(dep), std::end(dep), 0);

    dfs(u, 0);

    cout << *std::max_element(dep + 1, dep + n + 1) - 1 << endl;

    return 0;
}
