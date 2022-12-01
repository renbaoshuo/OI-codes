#include <iostream>
#include <algorithm>
#include <vector>

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

std::vector<long long> number_theoretic_transform(std::vector<long long> a) {
    // assert(a.size() == (1 << std::__lg(a.size())));
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
        long long wn = binpow(3, (mod - 1) / len);

        for (int i = 0; i < a.size(); i += len) {
            long long w = 1;

            for (int j = 0; j < m; j++) {
                long long u = a[i + j],
                          v = a[i + j + m] * w % mod;

                a[i + j] = ((u + v) % mod + mod) % mod;
                a[i + j + m] = ((u - v) % mod + mod) % mod;
                w = w * wn % mod;
            }
        }
    }

    return a;
}

class Poly : public std::vector<long long> {
  private:
  public:
    using std::vector<long long>::vector;

    Poly() = default;

    Poly(const std::vector<long long> &__v)
        : std::vector<long long>(__v) {}

    Poly(std::vector<long long> &&__v)
        : std::vector<long long>(std::move(__v)) {}
} poly;

Poly inv(Poly a) {
    if (a.size() == 1) return Poly{binpow(a[0], mod - 2)};

    int n = a.size(),
        k = 1 << (std::__lg(n << 1) + 1);
    Poly b{a};

    a.resize(k);
    a = number_theoretic_transform(a);

    b.resize(n + 1 >> 1);
    b = inv(b);
    b.resize(k);
    b = number_theoretic_transform(b);

    for (int i = 0; i < k; i++) {
        b[i] = (2 - a[i] * b[i] % mod + mod) % mod * b[i] % mod;
    }

    long long inv_k = binpow(k, mod - 2);
    b = number_theoretic_transform(b);
    std::transform(b.begin(), b.end(), b.begin(), [&](long long x) {
        return x * inv_k % mod;
    });
    std::reverse(b.begin() + 1, b.end());
    b.resize(n);

    return b;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    Poly f(n);

    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    auto g = inv(f);

    for (int i = 0; i < n; i++) {
        cout << g[i] << ' ';
    }

    cout << endl;

    return 0;
}
