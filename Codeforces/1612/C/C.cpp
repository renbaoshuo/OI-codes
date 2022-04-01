#include <bits/stdc++.h>

using namespace std;

int t, k;
long long x, ans;

inline long long calc(long long d) {
    return (d + 1) * d / 2;
}

inline long long calc2(long long d) {
    return (k * 2 - d + 1) * d / 2;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> k >> x;
        long long l = 0, r = k;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (calc(mid) <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (r < k) {
            ans = r + (calc(r) < x);
            cout << min(ans, k * 2ll - 1) << endl;
            continue;
        }
        x -= (k - 1ll) * k / 2ll;
        l = 0;
        r = k;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (calc2(mid) <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = (r + k - 1 + (calc2(r) < x));
        cout << min(ans, k * 2ll - 1) << endl;
    }
    return 0;
}
