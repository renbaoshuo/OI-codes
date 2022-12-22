#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

int t, a, b, x, y;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> a >> b >> x >> y;

        int g = std::__gcd(a, b) * 2;
        a %= g, b %= g, x %= g, y %= g;

        auto check = [&](int x, int y) -> bool {
            return x % g == 0 && y % g == 0;
        };

        cout << (check(x, y) || check(x + a, y + b) || check(x + b, y + a) || check(x + a + b, y + a + b) ? "Y" : "N") << endl;
    }

    return 0;
}
