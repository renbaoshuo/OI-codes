#include <bits/stdc++.h>

using namespace std;

const int mod = 200907;

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
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c, k;
        cin >> a >> b >> c >> k;
        if (b - a == c - b) {
            cout << (a + (b - a) % mod * (k - 1)) % mod << endl;
        } else if (b / a == c / b) {
            cout << a * binpow(b / a, k - 1) % mod << endl;
        }
    }
    return 0;
}
