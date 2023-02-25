#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;
const double eps = 1e-6;

int n, m, c;
double p, f[N][N];

bool check(double x) {
    for (int i = 0; i <= m; i++) {
        f[0][i] = x;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = std::min(x, f[i - 1][j] * (1.0 - p) + f[i][j - 1] * p + 1);
        }
    }

    return f[n][m] < x;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> c;

    p = c / 100.0;

    double l = 0,
           r = 1e9,
           res = 1e9;

    while (r - l > eps) {
        double mid = (l + r) / 2;

        if (check(mid)) {
            r = mid;
            res = mid;
        } else {
            l = mid;
        }
    }

    cout << std::fixed << std::setprecision(12) << res << endl;

    return 0;
}
