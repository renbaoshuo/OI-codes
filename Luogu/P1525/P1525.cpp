#include <iostream>
#include <array>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 20005;

int n, m;
std::array<int, N> color;
std::array<std::vector<std::pair<int, int>>, N> g;

bool dfs(int u, int color, int limit) {
    ::color[u] = color;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (w <= limit) continue;
        if (::color[v]) {
            if (::color[v] == color) return false;
        } else if (!dfs(v, 3 - color, limit)) {
            return false;
        }
    }

    return true;
}

bool check(int limit) {
    std::fill(color.begin(), color.end(), 0);

    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!dfs(i, 1, limit)) return false;
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    int l = 0, r = 1e9, ans = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
