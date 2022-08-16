#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205;

int n, m;
long long g[N][N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];

            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    if (g[k][l] - g[k][j - 1] - g[i - 1][l] + g[i - 1][j - 1] >= 0) {
                        ans = std::max(ans, static_cast<long long>(k - i + 1) * (l - j + 1));
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
