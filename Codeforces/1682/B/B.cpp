#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int t, n;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        cin >> n;

        int ans = -1;

        for (int i = 0, x; i < n; i++) {
            cin >> x;

            if (x != i) ans &= x;
        }

        cout << ans << endl;
    }

    return 0;
}
