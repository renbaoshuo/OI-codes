#include <cmath>
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

int n, x, ans, p[25];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= 16; i++) {
        p[i] = 1 << 16 - i;
    }

    while (n--) {
        ans = std::numeric_limits<int>::max();

        cin >> x;

        for (int i = 1; i <= 16; i++) {
            ans = std::min(ans, i + (int)ceil(1.0 * x / p[i]) * p[i] - x);
        }

        cout << ans - 1 << ' ';
    }

    cout << endl;

    return 0;
}
