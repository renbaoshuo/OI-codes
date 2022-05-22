#include <algorithm>
#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, n, a[N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        int ans = 2;

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        if (n <= 2) {
            cout << 1 << endl;
            continue;
        }

        std::sort(a + 1, a + 1 + n);

        for (int i = 3; i <= n; i++) {
            if (a[i] != a[i - 2]) ans++;
        }

        cout << (ans + 1) / 2 << endl;
    }

    return 0;
}
