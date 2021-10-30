#include <bits/stdc++.h>

using namespace std;

int t, n, a, ans;

int main() {
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            ans = max(ans, a - i);
        }
        cout << ans << endl;
    }
    return 0;
}
