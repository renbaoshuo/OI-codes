#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int t, n, a[1010];

signed main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        int cnt = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        std::sort(a, a + n);

        for (int i = 0; i < n; i++) {
            cnt += !a[i];
        }

        bool f = false;
        for (int i = 1; i < n; i++)
            f = f || (a[i] == a[i - 1]);

        cout << (cnt ? n - cnt : n + !f) << endl;
    }

    return 0;
}
