#include <iostream>
#include <numeric>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5005;
const int mod = 998244353;

int n, m, l[N], r[N], f[N][N];
int fac[N], inv[N], fac_inv[N];

int A(int n, int m) {
    if (n < m || n < 0 || m < 0) return 0;
    return static_cast<long long>(fac[n]) * fac_inv[n - m] % mod;
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

    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;

        l[x]++, r[y]++;
    }

    std::partial_sum(l + 1, l + 1 + m, l + 1);
    std::partial_sum(r + 1, r + 1 + m, r + 1);

    f[0][0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = f[i - 1][j];

            if (j - 1 >= 0 && r[i] - j + 1 >= 1) {
                f[i][j] = (static_cast<long long>(f[i][j]) + static_cast<long long>(f[i - 1][j - 1]) * (r[i] - j + 1) % mod + mod) % mod;
            }

            f[i][j] = static_cast<long long>(f[i][j]) * A(i - j - l[i - 1], l[i] - l[i - 1]) % mod;
        }
    }

    cout << f[m][n] << endl;

    return 0;
}
