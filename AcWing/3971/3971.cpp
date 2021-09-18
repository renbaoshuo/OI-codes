#include <bits/stdc++.h>

using namespace std;

int t, n, k, a, ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        ans = 0x3f3f3f3f;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (k % a == 0) {
                ans = min(ans, k / a);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
