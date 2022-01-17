#include <iostream>

using std::cin;
using std::cout;
using std::endl;

long long binpow(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << a << '^' << b << " mod " << p << '=' << binpow(a, b, p) << endl;
    return 0;
}
