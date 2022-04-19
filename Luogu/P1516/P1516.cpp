#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

long long x, y, n, m, l;

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }

    long long g = exgcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return g;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> x >> y >> m >> n >> l;

    long long b = n - m,
              c = x - y,
              xx, yy;

    if (b < 0) {
        b = -b;
        c = -c;
    }

    long long g = exgcd(b, l, xx, yy);

    if (c % g) {
        cout << "Impossible" << endl;
    } else {
        cout << (c / g * xx % (l / g) + (l / g)) % (l / g) << endl;
    }

    return 0;
}
