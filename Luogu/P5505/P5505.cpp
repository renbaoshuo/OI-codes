#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;
const int mod = 1e9 + 7;

int n, m, a[N], c[N][N], f[N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    c[0][0] = 1;

    for (int i = 1; i < N; ++i) {
        c[i][0] = 1;

        for (int j = 1; j <= i; ++j) {
            c[i][j] = (static_cast<long long>(c[i - 1][j - 1]) + c[i - 1][j]) % mod;
        }
    }

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        f[i] = 1;

        for (int j = 1; j <= m; j++) {
            f[i] = static_cast<long long>(f[i]) * c[n - i + a[j] - 1][n - i - 1] % mod;
        }

        f[i] = static_cast<long long>(f[i]) * c[n][i] % mod;
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans = (static_cast<long long>(ans) + f[i]) % mod;
        } else {
            ans = (static_cast<long long>(ans) - f[i] + mod) % mod;
        }
    }

    cout << ans << endl;

    return 0;
}
