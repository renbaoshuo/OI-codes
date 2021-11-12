#include <bits/stdc++.h>

using namespace std;

int n, h[1005], f[1005], g[1005], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (h[i] > h[j]) f[i] = max(f[i], f[j] + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        g[i] = 1;
        for (int j = n; j >= i; j--) {
            if (h[i] > h[j]) g[i] = max(g[i], g[j] + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i] + g[i] - 1);
    }
    cout << ans << endl;
    return 0;
}
