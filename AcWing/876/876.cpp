#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, a, p;

long long binpow(int a, int b, int m) {
    long long res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = 1ll * a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    while (n--) {
        cin >> a >> p;
        if (a % p) {
            cout << binpow(a, p - 2, p) << endl;
        } else {
            cout << "impossible" << endl;
        }
    }

    return 0;
}
