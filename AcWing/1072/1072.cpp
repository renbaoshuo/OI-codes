#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 10005;

int n, ans;
std::vector<std::pair<int, int>> g[N];

int dfs(int u, int fa) {
    int d1 = 0, d2 = 0;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa) continue;

        int d = dfs(v, u) + w;
        if (d >= d1) {
            d2 = d1;
            d1 = d;
        } else if (d > d2) {
            d2 = d;
        }
    }

    ans = std::max(ans, d1 + d2);

    return d1;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;

        g[u].push_back(std::make_pair(v, w));
        g[v].push_back(std::make_pair(u, w));
    }

    dfs(1, -1);

    cout << ans << endl;

    return 0;
}
