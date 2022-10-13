#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n;
long long a1, b1, a2, b2;

long long exgcd(long long a, long long b, long long& x, long long& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }

    long long g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

long long lcm(long long a, long long b) {
    return a / std::__gcd(a, b) * b;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        // $x \equiv a_i (mod b_i)$
        cin >> a2 >> b2;

        if (i == 1) {
            a1 = a2;
            b1 = b2;
        } else {
            long long x, y,
                g = exgcd(a1, a2, x, y),
                c = b2 - b1,
                m1 = a2 / g,
                m2 = lcm(a1, a2);

            if (c % g) {
                cout << -1 << endl;

                exit(0);
            }

            x = (static_cast<__int128>(x) * c / g % m1 + m1) % m1;
            b1 = ((a1 * x + b1) % m2 + m2) % m2;
            a1 = m2;
        }
    }

    cout << b1 % a1 << endl;

    return 0;
}
