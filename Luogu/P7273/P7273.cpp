#include <bits/stdc++.h>

using namespace std;

int n, w, a[300005], t[300005], ans;

int main() {
    cin >> n >> w;
    if (n == 1) {
        cout << 0 << endl;
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ans = n;
    for (int d = 0; (n - 1) * d + 1 <= w; d++) {
        for (int i = 0; i < n; i++) {
            if (a[i] > d * i && a[i] - (i - n + 1) * d <= w) {
                ans = min(ans, n - ++t[a[i] - d * i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > d * i) {
                t[a[i] - d * i] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
