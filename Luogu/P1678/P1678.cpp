#include <bits/stdc++.h>

using namespace std;

int m, n, q, ans, a[100005];

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a, a + m);
    for (int i = 0; i < n; i++) {
        cin >> q;
        int p = lower_bound(a, a + m, q) - a;
        if (p == m) {
            ans += q - a[m - 1];
        } else if (p == 0) {
            ans += a[0] - q;
        } else {
            ans += min(abs(a[p] - q), abs(q - a[p - 1]));
        }
    }
    cout << ans << endl;
    return 0;
}
