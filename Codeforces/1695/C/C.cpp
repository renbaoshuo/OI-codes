#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n, m;

        cin >> n >> m;

        std::vector<std::vector<int>>
            g(n, std::vector<int>(m)),
            f1(n, std::vector<int>(m)),
            f2(n, std::vector<int>(m));

        for (auto& e : g) {
            for (auto& v : e) {
                cin >> v;
            }
        }

        f1[0][0] = f2[0][0] = g[0][0];

        for (int i = 1; i < m; i++) {
            f1[0][i] = f2[0][i] = f1[0][i - 1] + g[0][i];
        }

        for (int i = 1; i < n; i++) {
            f1[i][0] = f2[i][0] = f1[i - 1][0] + g[i][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                f1[i][j] = std::max(f1[i - 1][j], f1[i][j - 1]) + g[i][j];
                f2[i][j] = std::min(f2[i - 1][j], f2[i][j - 1]) + g[i][j];
            }
        }

        cout << (f1[n - 1][m - 1] % 2 == 0 && f1[n - 1][m - 1] >= 0 && f2[n - 1][m - 1] <= 0 ? "YES" : "NO") << endl;
    }

    return 0;
}
