#include <bits/stdc++.h>

using namespace std;

long long t, n, k, a[5005], ans;

int main() {
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n, greater<long long>());
        for (int i = k; i < n; i++) {
            ans += a[i];
        }
        cout << max(ans, a[0]) << endl;
    }
    return 0;
}
