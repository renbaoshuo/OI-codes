#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

long long exgcd(long long a, long long b, long long& x, long long& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    long long g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        long long a, b, c, x, y;

        cin >> a >> b >> c;

        long long g = exgcd(a, b, x, y);

        if (c % g) {
            cout << -1 << endl;
        } else {  // c % g == 0
            x *= c / g;
            y *= c / g;

            long long p = b / g,
                      q = a / g;

            if (x < 0) {
                long long k = std::ceil((1.0 - x) / p);
                x += p * k;
                y -= q * k;
            } else {  // x >= 0
                long long k = (x - 1) / p;
                x -= p * k;
                y += q * k;
            }

            if (y > 0) {
                cout << (y - 1) / q + 1 << ' '
                     << x << ' '
                     << (y - 1) % q + 1 << ' '
                     << x + (y - 1) / q * p << ' '
                     << y << endl;
            } else {  // y <= 0
                cout << x << ' '
                     << y + q * static_cast<long long>(std::ceil((1.0 - y) / q)) << endl;
            }
        }
    }

    return 0;
}
