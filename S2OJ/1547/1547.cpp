#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;
const long long INF = 1e18;

int n, m, w[N];
long long f[N][2];
std::vector<int> g[N];

void dfs(int u, int fa) {
    int k = g[u].size() / 2 + 1;
    long long res = 0;
    std::vector<long long> a;

    for (int v : g[u]) {
        if (v == fa) continue;

        dfs(v, u);

        if (w[v] <= w[u]) {
            a.emplace_back(std::max(f[v][0] + w[v], f[v][1] + w[u]) - f[v][1] - m);
            res += f[v][1] + m;
        } else {
            a.emplace_back(f[v][0] + w[u] - std::max(f[v][0] + w[v], f[v][1] + m));
            res += std::max(f[v][0] + w[v], f[v][1] + m);
        }
    }

    std::sort(a.begin(), a.end(), std::greater<>());

    if (k - 1 > a.size()) {
        f[u][0] = -INF;
    } else {
        long long sum = res;

        for (int i = 0; i < k - 1; i++) sum += a[i];
        for (int i = k - 1; i < a.size(); i++) sum += std::max(0ll, a[i]);

        f[u][0] = sum;
    }

    if (k > a.size()) {
        f[u][1] = -INF;
    } else {
        long long sum = res;

        for (int i = 0; i < k; i++) sum += a[i];
        for (int i = k; i < a.size(); i++) sum += std::max(0ll, a[i]);

        f[u][1] = sum;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(1, 1);

    cout << f[1][1] << endl;

    return 0;
}
