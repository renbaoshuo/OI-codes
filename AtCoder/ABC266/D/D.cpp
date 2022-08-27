#include <iostream>
#include <algorithm>
#include <array>
#include <limits>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, min_t, max_t;
std::array<long long, 5> f[N];
std::array<std::pair<int, int>, N> snukes;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    min_t = std::numeric_limits<int>::max();
    max_t = std::numeric_limits<int>::min();
    std::fill(snukes.begin(), snukes.end(), std::make_pair(-1, 0));

    for (int i = 1, t, x, a; i <= n; i++) {
        cin >> t >> x >> a;

        snukes[t] = std::make_pair(x, a);
        min_t = std::min(min_t, t);
        max_t = std::max(max_t, t);
    }

    f[0][1] = f[0][2] = f[0][3] = f[0][4]
        = f[1][1] = f[1][2] = f[1][3] = f[1][4]
        = f[2][2] = f[2][3] = f[2][4]
        = f[3][3] = f[3][4]
        = std::numeric_limits<long long>::min();

    for (int i = 1; i <= max_t; i++) {
        std::copy_n(f[i - 1].begin(), std::min(i, 5), f[i].begin());

        if (snukes[i].first == -1) continue;

        long long x = std::numeric_limits<long long>::min();

        for (int j = 0; j <= 4; j++) {
            if (i - std::abs(j - snukes[i].first) < 0) continue;

            x = std::max(x, f[i - std::abs(j - snukes[i].first)][j] + snukes[i].second);
        }

        f[i][snukes[i].first] = std::max(f[i][snukes[i].first], x);
    }

    cout << std::max({f[max_t][0], f[max_t][1], f[max_t][2], f[max_t][3], f[max_t][4]}) << endl;

    return 0;
}
