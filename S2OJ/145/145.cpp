#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int inv[N], fac[N], inv_fac[N];

int C(int n, int m) {
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

    // ======

    int t;

    cin >> t;

    while (t--) {
        int n, m, k, res1 = 0, res2 = 0, res3 = 0, res4 = 0;

        cin >> n >> m >> k;

        for (int i = k & 1; i <= std::min(n, k); i += 2) {
            res1 = (res1 + C(n, i)) % mod;
        }

        for (int i = k & 1; i <= std::min(m, k); i += 2) {
            res2 = (res2 + C(m, i)) % mod;
        }

        if (n % 2 == 0 && m % 2 == 0) {
            for (int i = std::max(n - k, 0); i <= std::min(n, k); i += 2) {
                res3 = (res3 + C(n, i)) % mod;
            }

            for (int i = std::max(m - k, 0); i <= std::min(m, k); i += 2) {
                res4 = (res4 + C(m, i)) % mod;
            }
        }

        cout << ((static_cast<long long>(res1) * res2 % mod - static_cast<long long>(res3) * res4 % mod * inv[2] % mod) + mod) % mod << endl;
    }

    return 0;
}
