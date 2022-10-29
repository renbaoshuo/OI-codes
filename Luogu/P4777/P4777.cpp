#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

int n;
long long a1, b1, a2, b2;

long long exgcd(long long a, long long b, long long &x, long long &y) {
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

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> b2 >> a2;

        if (i == 1) {
            b1 = b2;
            a1 = a2;
        } else {
            long long x, y,
                g = exgcd(b1, b2, x, y),
                c = a2 - a1,
                m1 = b2 / g,
                m2 = b1 / g * b2;

            if (c % g) {
                cout << -1 << endl;

                exit(0);
            }

            x = static_cast<__int128>(x) * c / g % m1;
            a1 = ((a1 + b1 * x) % m2 + m2) % m2;
            b1 = m2;
        }
    }

    cout << a1 % b1 << endl;

    return 0;
}
