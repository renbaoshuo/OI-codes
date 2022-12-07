#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5,
          M = 2005;
const int mod = 1e9 + 7;

int n, m, a[N], b[N], inv[M << 2], fac[M << 2], inv_fac[M << 2], _f[M << 1][M << 1], *_pf[M << 1], **f, ans;

inline int C(int n, int m) {
    return static_cast<long long>(fac[n]) * inv_fac[m] % mod * inv_fac[n - m] % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i < M << 2; i++) {
        fac[i] = static_cast<long long>(fac[i - 1]) * i % mod;
    }

    inv[0] = inv[1] = 1;
    for (int i = 2; i < M << 2; i++) {
        inv[i] = static_cast<long long>(mod - (mod / i)) * inv[mod % i] % mod;
    }

    inv_fac[0] = inv_fac[1] = 1;
    for (int i = 2; i < M << 2; i++) {
        inv_fac[i] = static_cast<long long>(inv_fac[i - 1]) * inv[i] % mod;
    }

    for (int i = 0; i < M << 1; i++) {
        _pf[i] = _f[i] + M;
    }

    f = _pf + M;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];

        f[-a[i]][-b[i]]++;
    }

    for (int i = -2000; i <= 2000; i++) {
        for (int j = -2000; j <= 2000; j++) {
            f[i][j] = (static_cast<long long>(f[i][j]) + f[i - 1][j] + f[i][j - 1]) % mod;
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = (static_cast<long long>(ans) + f[a[i]][b[i]]) % mod;
    }

    for (int i = 1; i <= n; i++) {
        ans = ((static_cast<long long>(ans) - C(2 * a[i] + 2 * b[i], 2 * a[i])) % mod + mod) % mod;
    }

    cout << (static_cast<long long>(ans) * inv[2] % mod) << endl;

    return 0;
}
