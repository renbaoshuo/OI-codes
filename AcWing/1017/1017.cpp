#include <bits/stdc++.h>

using namespace std;

int t, n, h[105], f[105], ans;

int main() {
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        memset(f, 0x00, sizeof(f));
        for (int i = 1; i <= n; i++) {
            f[i] = 1;
            for (int j = 1; j < i; j++) {
                if (h[i] < h[j]) f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
        }
        memset(f, 0x00, sizeof(f));
        for (int i = n; i >= 1; i--) {
            f[i] = 1;
            for (int j = 1; j <= n; j++) {
                if (h[i] < h[j]) f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
