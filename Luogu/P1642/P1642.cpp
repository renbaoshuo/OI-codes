#include <iostream>
#include <algorithm>
#include <array>
#include <iomanip>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;
const double eps = 1e-4;

int n, m;
std::array<int, N> siz;
std::array<double, N> d;
std::array<std::array<double, N>, N> f;
std::array<std::vector<int>, N> g;
std::array<std::pair<int, int>, N> a;

void dfs(int u, int fa) {
    f[u][0] = 0;
    siz[u] = 1;

    for (int v : g[u]) {
        if (v == fa) continue;

        dfs(v, u);

        siz[u] += siz[v];

        for (int i = std::min(siz[u], m); ~i; i--) {
            for (int j = 0; j <= std::min(siz[v], i); j++) {
                f[u][i] = std::max(f[u][i], f[u][i - j] + f[v][j]);
            }
        }
    }

    for (int i = std::min(m, siz[u]); i; i--) {
        f[u][i] = f[u][i - 1] + d[u];
    }
}

bool check(double mid) {
    for (int i = 1; i <= n; i++) {
        d[i] = static_cast<double>(a[i].first) - mid * a[i].second;
    }

    std::for_each(f.begin(), f.end(), [&](auto &x) {
        std::fill(x.begin(), x.end(), std::numeric_limits<int>::min());
    });

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        if (f[i][m] > -eps) return true;
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    m = n - m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    double l = 0,
           r = 10000;

    while (r - l > eps) {
        double mid = (l + r) / 2;

        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << std::fixed << std::setprecision(1) << l << endl;

    return 0;
}
