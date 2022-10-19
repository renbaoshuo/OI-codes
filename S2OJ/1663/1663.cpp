#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 998244853;

int t, n, p[N], p1[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    p1[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        p[i] = (static_cast<long long>(p[i - 1]) * 10 % mod + 8) % mod;
        p1[i] = static_cast<long long>(p1[i - 1]) * 10 % mod;
    }

    cin >> t;

    while (t--) {
        cin >> n;

        int l = std::ceil(1.0 * n / 7);

        if (n == 1) {
            cout << -1 << endl;
        } else if (n == 2) {
            cout << 1 << endl;
        } else if (n == 3) {
            cout << 7 << endl;
        } else if (n == 4) {
            cout << 4 << endl;
        } else if (n == 5) {
            cout << 2 << endl;
        } else if (n == 6) {
            cout << 0 << endl;
        } else if (n == 7) {
            cout << 8 << endl;
        } else if (n == 8) {
            cout << 10 << endl;
        } else if (n == 9) {
            cout << 18 << endl;
        } else if (n == 10) {
            cout << 22 << endl;
        } else if (n % 7 == 0) {
            cout << p[l] << endl;
        } else if (n % 7 == 1) {
            cout << (static_cast<long long>(l - 2 > 0 ? p[l - 2] : 0) + static_cast<long long>(p1[l - 1])) % mod << endl;
        } else if (n % 7 == 2) {
            cout << (static_cast<long long>(l - 1 > 0 ? p[l - 1] : 0) + static_cast<long long>(p1[l - 1])) % mod << endl;
        } else if (n % 7 == 3) {
            cout << (static_cast<long long>(l - 3 > 0 ? p[l - 3] : 0) + static_cast<long long>(p1[l - 1]) * 2 % mod) % mod << endl;
        } else if (n % 7 == 4) {
            cout << (static_cast<long long>(l - 2 > 0 ? p[l - 2] : 0) + static_cast<long long>(p1[l - 1]) * 2 % mod) % mod << endl;
        } else if (n % 7 == 5) {
            cout << (static_cast<long long>(l - 1 > 0 ? p[l - 1] : 0) + static_cast<long long>(p1[l - 1]) * 2 % mod) % mod << endl;
        } else {  // n % 7 == 6
            cout << (static_cast<long long>(l - 1 > 0 ? p[l - 1] : 0) + static_cast<long long>(p1[l - 1]) * 6 % mod) % mod << endl;
        }
    }

    return 0;
}
