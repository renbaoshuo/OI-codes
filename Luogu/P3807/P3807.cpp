#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int t, n, m, p, fac[N], inv[N];

inline int C(int n, int m, int p) {
    if (m > n) return 0;
    return 1ll * fac[n] * inv[m] % p * inv[n - m] % p;
}

int lucas(int n, int m, int p) {
    if (!m) return 1;
    return static_cast<long long>(C(n % p, m % p, p)) * lucas(n / p, m / p, p) % p;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n >> m >> p;

        fac[0] = 1;
        for (int i = 1; i <= 100000; i++) {
            fac[i] = 1ll * fac[i - 1] * i % p;
        }

        inv[0] = inv[1] = 1;
        for (int i = 2; i <= 100000; i++) {
            inv[i] = static_cast<long long>(p - (p / i)) * inv[p % i] % p;
        }

        for (int i = 2; i <= 100000; i++) {
            inv[i] = static_cast<long long>(inv[i - 1]) * inv[i] % p;
        }

        cout << lucas(n + m, n, p) << endl;
    }

    return 0;
}
