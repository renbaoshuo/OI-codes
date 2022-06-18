#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 10;

int t, n, a[N];

signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n;

        int p = n << 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            if (!a[i]) p = std::min(p, i);
        }

        if (p != (n << 1)) {
            cout << (p & 1 ? "Joe" : "Mike") << endl;
        } else if (n & 1) {
            cout << "Mike" << endl;
        } else {
            int x = std::numeric_limits<int>::max(),
                y = std::numeric_limits<int>::max();

            int p1 = n, p2 = n;
            for (int i = 1; i <= n; i++) {
                if (i & 1) {
                    x = std::min(x, a[i]);
                } else {
                    y = std::min(y, a[i]);
                }
            }

            for (int i = 1; i <= n; i++) {
                if ((i & 1) && x == a[i])
                    p1 = std::min(p1, i);
                if (!(i & 1) && y == a[i])
                    p2 = std::min(p2, i);
            }

            cout << (x < y || x == y && p1 < p2 ? "Joe" : "Mike") << endl;
        }
    }

    return 0;
}
