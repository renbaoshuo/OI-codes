#include <bits/stdc++.h>

using namespace std;

long long binpow(long long a, long long b, long long p) {
    long long res = 1;
    a %= p;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << binpow(a, b, p) << endl;
    return 0;
}
