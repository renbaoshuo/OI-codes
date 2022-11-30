#include <iostream>
#include <algorithm>
#include <valarray>

using std::cin;
using std::cout;
const char endl = '\n';

const int mod = 998244353;

constexpr long long binpow(long long a, long long b) {
    a %= mod;

    long long res = 1;

    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

void number_theoretic_transform(std::valarray<long long>& a) {
    if (a.size() == 1) return;

    // assert(a.size() == 1 << std::__lg(a.size()));
    int k = std::__lg(a.size());

    for (int i = 0; i < a.size(); i++) {
        int t = 0;

        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                t |= 1 << (k - j - 1);
            }
        }

        if (i < t) std::swap(a[i], a[t]);
    }

    for (int len = 2; len <= a.size(); len <<= 1) {
        int m = len >> 1;

        long long wlen = binpow(3, (mod - 1) / len);

        for (int i = 0; i < a.size(); i += len) {
            long long w = 1;

            for (int j = 0; j < m; j++) {
                long long u = a[i + j],
                          v = a[i + j + m] * w % mod;

                a[i + j] = (u + v) % mod;
                a[i + j + m] = ((u - v) % mod + mod) % mod;
                w = w * wlen % mod;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    int k = 1 << (std::__lg(n + m) + 1),
        inv = binpow(k, mod - 2);
    std::valarray<long long> f(k), g(k);

    for (int i = 0; i <= n; i++) {
        cin >> f[i];
    }

    for (int i = 0; i <= m; i++) {
        cin >> g[i];
    }

    number_theoretic_transform(f);
    number_theoretic_transform(g);

    for (int i = 0; i < k; i++) {
        f[i] *= g[i];
    }

    number_theoretic_transform(f);
    std::reverse(std::begin(f) + 1, std::end(f));

    for (int i = 0; i <= n + m; i++) {
        cout << f[i] * inv % mod << ' ';
    }

    cout << endl;

    return 0;
}
