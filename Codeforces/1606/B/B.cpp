#include <bits/stdc++.h>

using namespace std;

int t;
long long n, k, f, ans;

int main() {
    cin >> t;
    while (t--) {
        f = 1;
        ans = 0;
        cin >> n >> k;
        while (f <= k && f < n) {
            ans++;
            f <<= 1;
        }
        if (f < n) {
            ans += (n - f) / k + !!((n - f) % k);
        }
        cout << ans << endl;
    }
    return 0;
}
