#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int t, x, y, c, a, b;

signed main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        cin >> a >> b >> c >> x >> y;
        cout << (std::max(0, x - a) + std::max(0, y - b) <= c
                     ? "YES"
                     : "NO")
             << endl;
    }

    return 0;
}
