#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

int t;
long long x, z;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> x >> z;

        if (!z) {
            cout << 0 << endl;
            continue;
        }

        long long yg = z / x,
                  gg = std::__gcd(x * x, yg),
                  g = std::sqrt(gg);

        if (gg != g * g || z % x) {
            cout << -1 << endl;
        } else {
            cout << yg / g << endl;
        }
    }

    return 0;
}
