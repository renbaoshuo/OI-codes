#include <bits/stdc++.h>

using namespace std;

int n, w, a[300005], t[3000005], ans;

int main() {
    cin >> n >> w;
    if (n == 1) {
        cout << 0 << endl;
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int d = 0; (n - 1) * d <= w; d++) {
        for (int i = 0; i < n; i++) {
            if (a[i] > d * i && a[i] + (n - i + 1) * d <= w) {
                ans = max(ans, ++t[a[i] - d * i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > d * i) {
                t[a[i] - d * i] = 0;
            }
        }
    }
    cout << n - ans << endl;
    return 0;
}
