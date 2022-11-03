#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int x, t, n, a[N];

bool is_prime(int x) {
    if (x < 2) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

int binpow(int a, int b, int p) {
    int res = 1;

    while (b) {
        if (b & 1) res = 1ll * res * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> t;

    while (t--) {
        cin >> n;

        if (n == 1) {
            cout << 2 << ' ' << 1 << endl;
        } else if (x == 1) {
            if (n % 2 == 1) {
                cout << 0 << endl;
            } else {
                cout << 2 << ' ';

                for (int i = 1; i <= n; i++) {
                    cout << (i % 2 ? n - i + 1 : i - 1) << ' ';
                }

                cout << endl;
            }
        } else {  // x == 2
            if (n == 2) {
                cout << 2 << ' ' << "1 2" << endl;
            } else if (n == 4) {
                cout << 2 << ' ' << "1 3 2 4" << endl;
            } else if (!is_prime(n)) {
                cout << 0 << endl;
            } else {
                cout << 2 << ' ' << 1 << ' ';

                for (int i = 2; i < n; i++) {
                    cout << static_cast<long long>(i) * binpow(i - 1, n - 2, n) % n << ' ';
                }

                cout << n << endl;
            }
        }
    }

    return 0;
}
