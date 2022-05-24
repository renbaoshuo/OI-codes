#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using std::cin;
using std::cout;

const char endl = '\n';

const int N = 2e4 + 5;

int n, ans;
int root, siz[N], max[N];
int p[10];
bool vis[N];
std::vector<std::pair<int, int>> g[N];

void find(int u, int fa, int tot) {
    siz[u] = 1;
    max[u] = 0;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa || vis[v]) continue;

        find(v, u, tot);

        siz[u] += siz[v];
        max[u] = std::max(max[u], siz[v]);
    }

    max[u] = std::max(max[u], tot - siz[u]);

    if (max[u] < max[root]) root = u;
}

void dis(int u, int fa, int sum) {
    p[sum % 3]++;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa || vis[v]) continue;

        dis(v, u, sum + w);
    }
}

int calc(int u, int w) {
    std::fill(p, p + 3, 0);
    dis(u, 0, w);
    return p[0] * p[0] + 2 * p[1] * p[2];
}

void solve(int u) {
    vis[u] = true;
    ans += calc(u, 0);

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (vis[v]) continue;

        ans -= calc(v, w);

        max[root = 0] = std::numeric_limits<int>::max();
        find(v, 0, siz[v]);
        solve(root);
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;

        g[u].push_back(std::make_pair(v, w % 3));
        g[v].push_back(std::make_pair(u, w % 3));
    }

    max[root = 0] = n;
    find(1, 0, n);
    solve(root);

    int gcd = std::__gcd(ans, n * n);

    cout << ans / gcd << '/' << n * n / gcd << endl;

    return 0;
}
