#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e7 + 5;

int t, p, a, d, n;
int fac[N], inv[N], fac_inv[N];

constexpr int binpow(int a, int b, int mod) {
    int res = 1;
    a %= mod;

    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % mod;
        a = static_cast<long long>(a) * a % mod;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> p;

    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = static_cast<long long>(fac[i - 1]) * i % p;
    }

    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = static_cast<long long>(p - (p / i)) * inv[p % i] % p;
    }

    fac_inv[0] = fac_inv[1] = 1;
    for (int i = 2; i < N; i++) {
        fac_inv[i] = static_cast<long long>(fac_inv[i - 1]) * inv[i] % p;
    }

    while (t--) {
        cin >> a >> d >> n;

        if (d == 0) {
            cout << binpow(a, n, p) << endl;
        } else {
            int k = static_cast<long long>(a) * inv[d] % p;

            if (k == 0 || n + k - 1 > p) {
                cout << 0 << endl;
            } else {
                cout << static_cast<long long>(fac[n + k - 1]) * fac_inv[k - 1] % p * binpow(d, n, p) % p << endl;
            }
        }
    }

    return 0;
}
