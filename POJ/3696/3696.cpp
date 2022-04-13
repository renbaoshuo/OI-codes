#include <algorithm>
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

int t;
long long l;

long long euler(long long x) {
    long long r = x;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            r = r / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) r = r / x * (x - 1);
    return r;
}

long long binmul(long long a, long long b, long long m) {
    unsigned long long c =
        (unsigned long long)a * b -
        (unsigned long long)((long double)a / m * b + 0.5L) * m;
    if (c < m) return c;
    return c + m;
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = binmul(res, a, m);
        a = binmul(a, a, m);
        b >>= 1;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    while (cin >> l, l) {
        long long d = std::__gcd(l, 8ll);
        long long n = euler(9ll * l / d);
        long long ans = std::numeric_limits<long long>::max();

        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (binpow(10, i, 9ll * l / d) == 1) ans = std::min(ans, i);
                if (binpow(10, n / i, 9ll * l / d) == 1) ans = std::min(ans, n / i);
            }
        }

        cout << "Case " << ++t << ": " << (ans == std::numeric_limits<long long>::max() ? 0 : ans) << endl;
    }

    return 0;
}
