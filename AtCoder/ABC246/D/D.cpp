#include <cmath>
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

long long n, a, b, ans = std::numeric_limits<long long>::max();

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    if (!n) {
        cout << 0 << endl;
        exit(0);
    }

    while (std::pow(a, 3) * 4 < n) b = ++a;
    while (b) {
        while (b && (a + b - 1) * (a * a + (b - 1) * (b - 1)) >= n) b--;
        ans = std::min(ans, (a + b) * (a * a + b * b));
        a++;
    }

    cout << ans << endl;

    return 0;
}
