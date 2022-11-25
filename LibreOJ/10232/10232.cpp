#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;
const int mod = 1e5 + 3;

int a, b, c, d, k, fac[N], inv[N], fac_inv[N], ans;

inline int C(int n, int m) {
    return static_cast<long long>(fac[n]) * fac_inv[m] % mod * fac_inv[n - m] % mod;
}

int f(int n, int m, int k) {
    if (k > n || k > m) return 0;
    return static_cast<long long>(C(n, k)) * C(m, k) % mod * fac[k] % mod;
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
        inv[i] = static_cast<long long>(mod - mod / i) * inv[mod % i] % mod;
    }

    fac_inv[0] = fac_inv[1] = 1;
    for (int i = 2; i < N; i++) {
        fac_inv[i] = static_cast<long long>(fac_inv[i - 1]) * inv[i] % mod;
    }

    cin >> a >> b >> c >> d >> k;

    for (int i = 0; i <= k; i++) {
        ans = (ans + static_cast<long long>(f(a, b, i)) * f(a + c - i, d, k - i)) % mod;
    }

    cout << ans << endl;

    return 0;
}
