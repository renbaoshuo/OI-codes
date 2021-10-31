#include <bits/stdc++.h>

using namespace std;

const int mod = 123456789;

long long k;

long long binpow(long long a, long long b) {
    long long res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

int main() {
    cin >> k;
    cout << binpow(2, k - 1) << endl;
    return 0;
}
