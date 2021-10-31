#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a[1005], ans = 0, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a, a + m);
    for (int i = 0; i < m; i++) {
        int now = a[i];
        if (now * (m - i) > ans && m - i <= n) {
            sum = now;
            ans = now * (m - i);
        }
    }
    cout << sum << ' ' << ans;
    return 0;
}
