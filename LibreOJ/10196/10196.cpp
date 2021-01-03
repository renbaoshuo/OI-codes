#include <bits/stdc++.h>

using namespace std;

const int mod = 100003;

long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    long long m, n;
    cin >> m >> n;
    cout << (binpow(m, n) - binpow(m - 1, n - 1) * m % mod + mod) % mod << endl;
    return 0;
}
