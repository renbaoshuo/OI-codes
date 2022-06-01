#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

int t;
long long a;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        cin >> a;

        if (a % 2 == 0 && a >= 4) {
            cout << a / 6 + !!(a % 6) << ' ' << (a % 4 == 2 ? (a - 3) / 4 + 1 : a / 4) << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
