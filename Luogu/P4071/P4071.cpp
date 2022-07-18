#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int t, n, m, fac[N], inv[N], fac_inv[N], d[N];

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

    d[2] = 1;
    for (int i = 3; i < N; i++) {
        d[i] = static_cast<long long>(i - 1) * (d[i - 1] + d[i - 2]) % mod;
    }

    cin >> t;

    while (t--) {
        cin >> n >> m;

        cout << (n == m ? 1 : static_cast<long long>(d[n - m]) * C(n, m) % mod) << endl;
    }

    return 0;
}
