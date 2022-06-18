#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 45;

int t, n, m, a[N][N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        int max = std::numeric_limits<int>::min();
        std::pair<int, int> maxp;

        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];

                if (a[i][j] >= max) {
                    maxp = std::make_pair(i, j);

                    max = a[i][j];
                }
            }
        }

        int i = maxp.first, j = maxp.second;
        int tx = n - i + 1,
            ty = m - j + 1;

        // cout << std::max({i * j, i * ty, tx * j, tx * ty}) << endl;
        cout << std::max(i, tx) * std::max(j, ty) << endl;
    }

    return 0;
}
