#include <iostream>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

class Matrix {
  private:
    long long data[10][10], mod;

  public:
    Matrix(long long _mod = 1e9 + 7)
        : mod(_mod) {
        memset(data, 0x00, sizeof(data));
    }

    long long *operator[](long long i) {
        return data[i];
    }

    Matrix operator*(Matrix b) const {
        Matrix c(mod);

        int n = 2;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    c[i][j] = (c[i][j] + data[i][k] * b[k][j] % mod) % mod;
                }
            }
        }

        return c;
    }
};

Matrix binpow(Matrix a, long long k, long long p) {
    Matrix res(p);
    res[1][1] = 1;
    res[1][2] = 1;

    while (k) {
        if (k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }

    return res;
}

long long fib(long long n, long long p) {
    if (n <= 2) {
        return n != 0;
    }

    Matrix tmp(p);

    tmp[1][1] = 1, tmp[1][2] = 1;
    tmp[2][1] = 1, tmp[2][2] = 0;

    return binpow(tmp, n - 2, p)[1][1];
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    long long g = exgcd(b, a % b, y, x);
    y -= a / b * x;

    return g;
}

long long calc(long long x, long long y) {
    if (x == 0) return 0;

    return x < 0 ? -(-x + y - 1) / y : x / y;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        long long i, l, r, k, p, m, x, y;

        cin >> i >> l >> r >> k >> p >> m;

        long long f1 = fib(k - 2, p),
                  f2 = fib(k - 1, p);

        long long a = f2,
                  b = p,
                  c = ((m - i % p * f1 % p) + p) % p,
                  g = std::__gcd(a, b);

        if (c % g) {
            cout << 0 << endl;

            continue;
        }

        a /= g, b /= g, c /= g;
        exgcd(a, b, x, y);
        x = (x * c % b + b) % b;

        cout << calc(r - x, b) - calc(l - x - 1, b) << endl;
    }

    return 0;
}
