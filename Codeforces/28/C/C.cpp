#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55;

int n, m, a[N];
long long c[N][N];
double f[N][N][N], sum, ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    c[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        c[i][0] = 1;

        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    f[0][0][0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
                for (int l = 0; l <= n - j; l++) {
                    int p = std::max(static_cast<int>(std::ceil(static_cast<double>(l) / a[i])), k);

                    f[i][j + l][p] += f[i - 1][j][k] * c[n - j][l];
                }
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        sum += f[m][n][i];
    }

    for (int i = 1; i <= n; i++) {
        ans += static_cast<double>(i) * f[m][n][i];
    }

    cout << std::fixed << std::setprecision(20) << ans / sum << endl;

    return 0;
}
