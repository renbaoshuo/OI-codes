#include <bits/stdc++.h>

using namespace std;

int n, k, p, a, b, c, d, s[20000005], pre[20000005], suc[20000005], ans;

int main() {
    cin >> n >> k >> p;
    cin >> a >> b >> c >> d;
    s[1] = a;
    for (int i = 2; i <= n; i++) {
        s[i] = (1ll * s[i - 1] * b + c) % d;
    }
    for (int i = 1; i <= n; i++) {
        if ((i - 1) % k) {
            pre[i] = 1ll * pre[i - 1] * s[i] % p;
        } else {
            pre[i] = s[i];
        }
    }
    for (int i = n; i > 0; i--) {
        if (i % k) {
            suc[i] = 1ll * suc[i + 1] * s[i] % p;
        } else {
            suc[i] = s[i];
        }
    }
    for (int i = 1; i <= n - k + 1; i++) {
        if ((i - 1) % k) {
            ans ^= 1ll * suc[i] * pre[i + k - 1] % p;
        } else {
            ans ^= pre[i + k - 1];
        }
    }
    cout << ans << endl;
    return 0;
}
