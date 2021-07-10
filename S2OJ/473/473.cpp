#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long n, m;

long long phi(long long x) {
    long long ans = x;
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0) {
            ans = ans / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (n > 1) ans = ans / x * (x - 1);
    return ans;
}

int main() {
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", (long long)(n % mod) * (m % mod) % mod * (phi(n) % mod) % mod * (phi(m) % mod) % mod);
    return 0;
}