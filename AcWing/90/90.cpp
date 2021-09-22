#include <bits/stdc++.h>

using namespace std;

long long bintimes(long long a, long long b, long long m) {
    a %= m;
    long long res = 0;
    while (b > 0) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << bintimes(a, b, p) << endl;
    return 0;
}
