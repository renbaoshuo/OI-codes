#include <bits/stdc++.h>

using namespace std;

long long n, m, k, a[100005], sum[100005], ans;

long long getSum(long long l, long long r) {
    long long len = r - l + 1;
    if (len % 2 == 0) {
        long long mid = l + (len / 2) - 1;
        return sum[r] - sum[mid] - (sum[mid] - sum[l - 1]);
    } else {
        long long mid = l + r >> 1;
        return sum[r] - sum[mid] - (sum[mid - 1] - sum[l - 1]);
    }
    return -1;
}

bool check(long long x) {
    for (long long i = 1; i + x - 1 <= n; i++) {
        if (getSum(i, i + x - 1) <= k) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> k;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    long long l = 1, r = n;
    while (l <= r) {
        long long mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
