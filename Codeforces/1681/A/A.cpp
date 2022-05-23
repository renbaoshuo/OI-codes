#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55;

int t, n, m;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        int x1 = 0, x2 = 0;
        cin >> n;

        for (int i = 1, x; i <= n; i++) {
            cin >> x;

            x1 = std::max(x, x1);
        }

        cin >> m;

        for (int i = 1, x; i <= m; i++) {
            cin >> x;

            x2 = std::max(x, x2);
        }

        if (x1 > x2) {
            cout << "Alice" << endl
                 << "Alice" << endl;
        } else if (x1 < x2) {
            cout << "Bob" << endl
                 << "Bob" << endl;
        } else {
            cout << "Alice" << endl
                 << "Bob" << endl;
        }
    }

    return 0;
}
