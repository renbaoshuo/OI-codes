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

void number_theoretic_transform(std::vector<long long> &a) {
    if (a.size() == 1) return;

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

    Poly operator*(const Poly &b) const {
        int n = size() - 1,
            m = b.size() - 1,
            k = 1 << (std::__lg(n + m) + 1),
            inv = binpow(k, mod - 2);

        std::vector<long long> f(*this), g(b);

        f.resize(k);
        number_theoretic_transform(f);
        g.resize(k);
        number_theoretic_transform(g);

        for (int i = 0; i < k; i++) {
            f[i] = f[i] * g[i] % mod;
        }

        number_theoretic_transform(f);
        // assert(f.size() > 0)
        std::reverse(f.begin() + 1, f.end());

        std::vector<long long> res(n + m + 1);

        for (int i = 0; i <= n + m; i++) {
            res[i] = f[i] * inv % mod;
        }

        return Poly(res);
    }
} poly;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    Poly f(n + 1), g(m + 1);

    for (int i = 0; i <= n; i++) {
        cin >> f[i];
    }

    for (int i = 0; i <= m; i++) {
        cin >> g[i];
    }

    auto res = f * g;

    for (int x : res) cout << x << ' ';

    cout << endl;

    return 0;
}
