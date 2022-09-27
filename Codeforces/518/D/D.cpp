#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

int n, t;
double p, f[N][N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p >> t;

    f[0][0] = 1;
    for (int i = 1; i <= t; i++) {
        f[i][0] = (1.0 - p) * f[i - 1][0];

        for (int j = 1; j < n; j++) {
            f[i][j] = p * f[i - 1][j - 1] + (1.0 - p) * f[i - 1][j];
        }

        f[i][n] = f[i - 1][n] + p * f[i - 1][n - 1];
    }

    for (int i = 1; i <= n; i++) {
        ans += f[t][i] * i;
    }

    cout << std::fixed << std::setprecision(6) << ans << endl;

    return 0;
}
