#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

long long a, b, d, m, ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> a >> b;

    d = a * a - b * 4;

    if (d == 0) {
        cout << "inf" << endl;

        exit(0);
    } else if (d < 0) {
        d *= -1;
        m = std::sqrt(d);

        for (long long q = 1; q <= m; q++) {
            if (d % q == 0) {
                long long p = d / q;

                long long x = p - q - 2 * a,
                          y = p + q;

                if (x % 4 || y % 4) continue;

                x /= 4, y /= 4;

                if (x >= 0 && y >= x) ans++;
            }
        }
    } else {  // d > 0
        m = std::sqrt(d);

        for (long long q = 1; q <= m; q++) {
            if (d % q == 0) {
                long long p = d / q;

                long long x = p + q - 2 * a,
                          y = p - q;

                if (x % 4 || y % 4) continue;

                x /= 4, y /= 4;

                if (x >= 0 && y >= x) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
