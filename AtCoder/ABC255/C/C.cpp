#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

long long x, a, d, n;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> a >> d >> n;

    if (d > 0) {
        if (x <= a) {
            cout << std::abs(a - x) << endl;
        } else if (x >= a + (n - 1) * d) {
            cout << std::abs(x - a - (n - 1) * d) << endl;
        } else {
            long long k = (x - a) / d;

            cout << std::min({
                        std::abs(a + k * d - x),
                        std::abs(a + (k - 1) * d - x),
                        std::abs(a + (k + 1) * d - x),
                        std::abs(a + (k - 2) * d - x),
                        std::abs(a + (k + 2) * d - x),
                    })
                 << endl;
        }
    } else {
        if (x >= a) {
            cout << std::abs(x - a) << endl;
        } else if (x <= a + (n - 1) * d) {
            cout << std::abs(a + (n - 1) * d - x) << endl;
        } else {
            long long k = (x - a) / d;

            cout << std::min({
                        std::abs(a + k * d - x),
                        std::abs(a + (k - 1) * d - x),
                        std::abs(a + (k + 1) * d - x),
                        std::abs(a + (k - 2) * d - x),
                        std::abs(a + (k + 2) * d - x),
                    })
                 << endl;
        }
    }

    return 0;
}
