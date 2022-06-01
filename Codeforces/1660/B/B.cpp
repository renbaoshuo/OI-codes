#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, n, a[N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        std::sort(a + 1, a + n + 1);
        if (n == 1) {
            cout << (a[1] == 1 ? "YES" : "NO") << endl;
        } else {
            cout << (a[n] - a[n - 1] > 1 ? "NO" : "YES") << endl;
        }
    }

    return 0;
}
