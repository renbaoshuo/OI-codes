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
            k = 1 << (std::__lg(n + m) + 1),
            inv = binpow(k, mod - 2);

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

    Poly rev_f{f}, rev_g{g};

    std::reverse(rev_f.begin(), rev_f.end());
    std::reverse(rev_g.begin(), rev_g.end());
    rev_g.resize(n - m + 1);
    rev_g = Poly::inv(rev_g);
    rev_f = rev_g * rev_f;

    Poly q(n - m + 1), r(m);

    for (int i = 0; i <= n - m; i++) {
        q[i] = rev_f[n - m - i];
    }

    g = g * q;

    for (int i = 0; i < m; i++) {
        r[i] = ((f[i] - g[i]) % mod + mod) % mod;
    }

    for (int i = 0; i <= n - m; i++) {
        cout << q[i] << ' ';
    }

    cout << endl;

    for (int i = 0; i < m; i++) {
        cout << r[i] << ' ';
    }

    cout << endl;

    return 0;
}
