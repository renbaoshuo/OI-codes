#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;
const int mod = 1e9 + 7;

int n, m, fac[N], inv[N], fac_inv[N], f[N][N][2][2], g[N], ans;

inline int C(int n, int m) {
    return static_cast<long long>(fac[n]) * fac_inv[m] % mod * fac_inv[n - m] % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = static_cast<long long>(fac[i - 1]) * i % mod;
    }

    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = static_cast<long long>(mod - (mod / i)) * inv[mod % i] % mod;
    }

    fac_inv[0] = fac_inv[1] = 1;
    for (int i = 2; i < N; i++) {
        fac_inv[i] = static_cast<long long>(fac_inv[i - 1]) * inv[i] % mod;
    }

    cin >> n >> m;

    f[1][0][0][0] = f[1][1][0][1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i][0][0][0] = 1;

        for (int j = 1; j <= i; j++) {
            f[i][j][0][0] = (static_cast<long long>(f[i - 1][j - 1][0][0]) + f[i - 1][j][0][0] + f[i - 1][j][1][0]) % mod;
            f[i][j][0][1] = (static_cast<long long>(f[i - 1][j - 1][0][0]) + f[i - 1][j - 1][1][0]) % mod;
            f[i][j][1][0] = (static_cast<long long>(f[i - 1][j - 1][0][1]) + f[i - 1][j][1][1] + f[i - 1][j][0][1]) % mod;
            f[i][j][1][1] = (static_cast<long long>(f[i - 1][j - 1][0][1]) + f[i - 1][j - 1][1][1]) % mod;
        }
    }

    f[n][0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        f[n][i][0][0] = (static_cast<long long>(f[n - 1][i - 1][0][0]) + f[n - 1][i][0][0] + f[n - 1][i][1][0]) % mod;
        f[n][i][1][0] = (static_cast<long long>(f[n - 1][i - 1][0][1]) + f[n - 1][i][0][1] + f[n - 1][i][1][1]) % mod;
    }

    for (int i = 0; i <= n; i++) {
        g[i] = (static_cast<long long>(f[n][i][0][0]) + f[n][i][1][0]) % mod * fac[n - i] % mod;
    }

    for (int i = m; i <= n; i++) {
        ans = (static_cast<long long>(ans) + (static_cast<long long>((i - m) & 1 ? -1 : 1) * C(i, m) * g[i] % mod + mod) % mod) % mod;
    }

    cout << ans << endl;

    return 0;
}
