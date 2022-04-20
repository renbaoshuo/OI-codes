#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int mod = 200907;

int t, a, b, c, k;

int binpow(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        cin >> a >> b >> c >> k;

        if (a - b == b - c) {  // 等差数列
            cout << (a + 1ll * (b - a) * (k - 1)) % mod << endl;
        } else {  // 等比数列
            cout << 1ll * a * binpow(b / a, k - 1) % mod << endl;
        }
    }

    return 0;
}
