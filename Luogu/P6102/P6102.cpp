#include <bits/stdc++.h>

using namespace std;

int n, x, y, xs, ys, sum;
unsigned int ans, a[500005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sum = n * n;
    for (int i = 0; i < 32; i++) {
        x = y = xs = ys = 0;
        for (int j = 1; j <= n; j++) {
            if ((a[j] >> i) & 1) xs++;
        }
        ys = n - xs;
        for (int j = 1; j <= n; j++) {
            x = xs * n + ys * xs;
            y = ys * n + xs * ys;
        }
        ans += (x * y + (sum - x) * (sum - y)) << i;
    }
    cout << ans << endl;
    return 0;
}
