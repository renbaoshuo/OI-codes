#include <bits/stdc++.h>

using namespace std;

long long phi(long long x) {
    long long r = x;
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0) {
            r = r / i * (i - 1);
            while (x % i == 0) {
                x /= i;
            }
        }
    if (x > 1) {
        r = r / x * (x - 1);
    }
    return r;
}

long long pow(long long x, long long y, long long mod) {
    long long r = 1;
    while (y) {
        if (y & 1) r = (r * x) % mod;
        x = (x * x) % mod, y >>= 1;
    }
    return r;
}

long long f(long long x) {
    if (x == 1) return 0;
    long long n = phi(x);
    return pow(2, n + f(n), x);
}

int main() {
    long long t, x;
    cin >> t;
    while (t--) {
        cin >> x;
        cout << f(x) << endl;
    }
    return 0;
}
