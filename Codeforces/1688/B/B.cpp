#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, n, a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        int ans = 0;

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            a[i] = __builtin_ffs(a[i]) - 1;
        }

        ans = std::max(*std::min_element(a + 1, a + 1 + n) - 1, 0);

        for (int i = 1; i <= n; i++) {
            if (a[i] > 0) ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
