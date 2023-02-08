#include <iostream>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;
const int mod = 1e9 + 9;

int n, k, inv[N], fac[N], inv_fac[N], a[N], b[N], l[N], f[N][N], g[N], ans;

inline int C(int n, int m) {
    return static_cast<long long>(fac[n]) * inv_fac[m] % mod * inv_fac[n - m] % mod;
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

    inv_fac[0] = inv_fac[1] = 1;
    for (int i = 2; i < N; i++) {
        inv_fac[i] = static_cast<long long>(inv_fac[i - 1]) * inv[i] % mod;
    }

    cin >> n >> k;

    if ((n - k) % 2 == 1) {
        cout << 0 << endl;

        exit(0);
    }

    std::copy_n(std::istream_iterator<int>(cin), n, a + 1);
    std::copy_n(std::istream_iterator<int>(cin), n, b + 1);

    std::sort(a + 1, a + 1 + n);
    std::sort(b + 1, b + 1 + n);
    std::transform(a + 1, a + 1 + n, l + 1, [&](int x) {
        return std::distance(b + 1, std::lower_bound(b + 1, b + 1 + n, x));
    });

    f[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        f[i][0] = f[i - 1][0];

        for (int j = 1; j <= i; j++) {
            f[i][j] = (static_cast<long long>(f[i - 1][j]) + static_cast<long long>(f[i - 1][j - 1]) * (l[i] - j + 1) % mod) % mod;
        }
    }

    for (int i = 0; i <= n; i++) {
        g[i] = static_cast<long long>(f[n][i]) * fac[n - i] % mod;
    }

    int w = (n + k) >> 1;
    for (int i = w; i <= n; i++) {
        if ((i - w) & 1) {
            ans = (static_cast<long long>(ans) - static_cast<long long>(C(i, w)) * g[i] % mod + mod) % mod;
        } else {
            ans = (static_cast<long long>(ans) + static_cast<long long>(C(i, w)) * g[i] % mod) % mod;
        }
    }

    cout << ans << endl;

    return 0;
}
