#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int n, q, a[200005], x, l, r, ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (q--) {
        cin >> x >> l >> r;
        ans = 0;
        for (int i = l; i <= r; i++) {
            ans = max(ans, (a[i] ^ x));
        }
        cout << ans << endl;
    }
    return 0;
}
