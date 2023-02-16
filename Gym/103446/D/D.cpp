#include <iostream>
#include <cmath>
#include <experimental/numeric>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

void solve() {
    long long p, q;

    cin >> p >> q;

    long long g = std::experimental::gcd(p, q);

    p /= g, q /= g;

    for (int i = 1; i * i <= q; i++) {
        if (q % i == 0) {
            long long a = i, b = q / i;

            if (a * a + b * b == p) {
                cout << a << ' ' << b << endl;

                return;
            }
        }
    }

    cout << 0 << ' ' << 0 << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) solve();

    return 0;
}
