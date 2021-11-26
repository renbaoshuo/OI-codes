#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int t, n, l, r, k, a[105];

int main() {
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> l >> r >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        std::sort(a, a + n);
        for (int i = 0; i < n; i++) {
            if (k < a[i]) break;
            if (l <= a[i] && a[i] <= r) {
                k -= a[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
