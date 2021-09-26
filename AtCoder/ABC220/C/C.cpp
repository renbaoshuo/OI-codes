#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int n;
long long a[100005], b, x, s, ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b += a[i];
    }
    cin >> x;
    s = (x / b) * b;
    ans = (x / b) * n;
    if (x % b == 0) {
        cout << ++ans << endl;
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        s += a[i];
        if (s > x) {
            ans += i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
