#include <iostream>
#include <algorithm>
#include <array>
#include <iomanip>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2505;
const double eps = 1e-4;

int k, n;
std::array<int, N> siz;
std::array<double, N> d;
std::array<std::array<double, N>, N> f;
std::array<std::vector<int>, N> g;
std::array<std::pair<int, int>, N> a;

void dfs(int u) {
    f[u][1] = d[u];
    siz[u] = 1;

    for (int v : g[u]) {
        dfs(v);

        siz[u] += siz[v];

        for (int i = std::min(siz[u], k + 1); i; i--) {
            for (int j = 0; j <= std::min(siz[v], i - 1); j++) {
                f[u][i] = std::max(f[u][i], f[u][i - j] + f[v][j]);
            }
        }
    }
}

bool check(double mid) {
    for (int i = 1; i <= n; i++) {
        d[i] = static_cast<double>(a[i].second) - mid * a[i].first;
    }

    std::for_each(f.begin(), f.end(), [&](auto &x) {
        std::fill(x.begin(), x.end(), std::numeric_limits<int>::min());
    });

    dfs(0);

    return f[0][k + 1] >= 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;

    for (int i = 1, r; i <= n; i++) {
        cin >> a[i].first >> a[i].second >> r;

        g[r].emplace_back(i);
    }

    double l = 0,
           r = 10000;

    while (r - l > eps) {
        double mid = (l + r) / 2;

        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << std::fixed << std::setprecision(3) << l << endl;

    return 0;
}
