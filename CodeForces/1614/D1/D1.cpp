#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int n;
long long a[100005], cnt[5000005], f[5000005], max, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        max = std::max(max, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                cnt[j]++;
                if (j * j != a[i]) {
                    cnt[a[i] / j]++;
                }
            }
        }
    }
    for (int i = 1; i <= max; i++) {
        f[i] = cnt[i] * i;
    }
    for (int i = max; i > 0; i--) {
        for (int j = i << 1; j <= max; j += i) {
            f[i] = std::max(f[i], f[j] + (cnt[i] - cnt[j]) * i);
        }
        ans = std::max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}
