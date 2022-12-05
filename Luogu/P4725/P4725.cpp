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

class Poly : public std::vector<long long> {
  private:
    static void number_theoretic_transform(std::vector<long long> &a) {
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

    static void dft(std::vector<long long> &a) {
        number_theoretic_transform(a);
    }

    static void idft(std::vector<long long> &a) {
        number_theoretic_transform(a);
        std::reverse(a.begin() + 1, a.end());
        long long inv = binpow(a.size(), mod - 2);
        std::transform(a.begin(), a.end(), a.begin(), [&](long long x) {
            return x * inv % mod;
        });
    }

    static Poly derivative(const Poly &a) {
        Poly b{a};

        for (int i = 1; i < a.size(); i++) {
            b[i - 1] = b[i] * i % mod;
        }

        b[a.size() - 1] = 0;

        return b;
    }

    static Poly integrate(const Poly &a) {
        Poly b{a};

        for (int i = a.size() - 1; i >= 1; i--) {
            b[i] = b[i - 1] * binpow(i, mod - 2) % mod;
        }

        b[0] = 0;

        return b;
    }

  public:
    using std::vector<long long>::vector;

    Poly() = default;

    Poly(const std::vector<long long> &__v)
        : std::vector<long long>(__v) {}

    Poly(std::vector<long long> &&__v)
        : std::vector<long long>(std::move(__v)) {}

    Poly operator*(const Poly &b) {
        int n = size() - 1,
            m = b.size() - 1,
            k = 1 << (std::__lg(n + m) + 1);
        long long inv = binpow(k, mod - 2);

        std::vector<long long> f(*this), g(b);

        f.resize(k);
        dft(f);
        g.resize(k);
        dft(g);

        for (int i = 0; i < k; i++) {
            f[i] = f[i] * g[i] % mod;
        }

        idft(f);
        f.resize(n + m + 1);

        return Poly(f);
    }

    Poly operator/(const Poly &b) {
        Poly c{inv(b)};

        return *this * c;
    }

    static Poly inv(Poly a) {
        if (a.size() == 1) return Poly{binpow(a[0], mod - 2)};

        int n = a.size(),
            k = 1 << (std::__lg(n << 1) + 1);
        Poly b{a};

        a.resize(k);
        dft(a);

        b.resize(n + 1 >> 1);
        b = inv(b);
        b.resize(k);
        dft(b);

        for (int i = 0; i < k; i++) {
            b[i] = (2 - a[i] * b[i] % mod + mod) % mod * b[i] % mod;
        }

        idft(b);
        b.resize(n);

        return b;
    }

    static Poly ln(Poly f) {
        Poly a{derivative(f)},
            b{inv(f)},
            res{integrate(a * b)};

        res.resize(f.size());

        return res;
    }
} poly;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    Poly a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Poly b = Poly::ln(a);

    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }

    cout << endl;

    return 0;
}
