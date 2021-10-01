#include <bits/stdc++.h>

using namespace std;

int n;
long long x, a[1000005], pre[1000005], suf[1000005], ans;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] | a[i];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] | a[i];
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, pre[i - 1] | (a[i] * x) | suf[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
