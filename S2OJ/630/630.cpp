#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

long long n, ans, x[3005], y[3005], t, l;
double b[10000005];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    ans = n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        t = 0;
        l = 1;
        for (int j = i - 1; j > 0; j--) {
            b[++t] = x[i] - x[j] ? (double)(y[i] - y[j]) / (double)(x[i] - x[j]) : 0x3f3f3f3f3f3f3f3f;
        }
        sort(b + 1, b + 1 + t);
        for (int j = 2; j <= t; j++) {
            if (b[j] == b[j - 1]) {
                l++;
            } else {
                ans -= l * (l - 1) / 2;
                l = 1;
            }
        }
        ans -= l * (l - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
