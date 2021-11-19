#include <bits/stdc++.h>

using namespace std;

long long n, m, l, r, ans, a[1000005];

bool check(long long x) {
    long long t = 0;
    for (long long i = 1; i <= n; i++) {
        if (a[i] > x) {
            t += a[i] - x;
        }
    }
    return t >= m;
}

int main() {
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }
    while (l <= r) {
        long long mid = l + r >> 1;
        if (check(mid)) {
            l = (ans = mid) + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
