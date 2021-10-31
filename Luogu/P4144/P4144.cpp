#include <bits/stdc++.h>

using namespace std;

int n, b;
long long p, a, x;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    cin >> n >> b >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        x = max(a, x);
    }
    cout << binpow(2 * x + 233, b, p) % p << endl;
    return 0;
}
