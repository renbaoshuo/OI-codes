#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e7 + 5;

int t, mod, p, primes[N], fac[N], fac_phi[N];
bool not_prime[N];

int binpow(int a, int b) {
    int res = 1;

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

    cin >> t >> mod;

    for (int i = 2; i < N; i++) {
        if (!not_prime[i]) primes[++p] = i;

        for (int j = 1; j <= p && i * primes[j] < N; j++) {
            not_prime[i * primes[j]] = true;

            if (i % primes[j] == 0) break;
        }
    }

    fac[0] = 1;

    for (int i = 1; i < N; i++) {
        if (i % mod) {
            fac[i] = static_cast<long long>(fac[i - 1]) * i % mod;
        } else {
            fac[i] = fac[i - 1];
        }
    }

    fac_phi[1] = 1;

    for (int i = 2; i < N; i++) {
        if (not_prime[i]) {
            fac_phi[i] = static_cast<long long>(fac_phi[i - 1]) * i % mod;
        } else {
            fac_phi[i] = static_cast<long long>(fac_phi[i - 1]) * (i - 1) % mod;
        }
    }

    while (t--) {
        int n, m;

        cin >> n >> m;

        cout << (n / mod > m / mod ? 0 : static_cast<long long>(fac[n]) * fac_phi[m] % mod * binpow(fac[m], mod - 2) % mod) << endl;
    }

    return 0;
}
