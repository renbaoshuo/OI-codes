#include <bits/stdc++.h>

using namespace std;

int n, m, k[1000005], b[1000005];
long long c[1000005], s, ans;

bool check(int t) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        c[i] = 1ll * k[i] * t + b[i];
    }
    nth_element(c, c + m, c + n, greater<long long>());
    for (int i = 0; i < m; i++) {
        if (c[i] >= 0) sum += c[i];
        if (sum >= s) return true;
    }
    return false;
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) {
        cin >> k[i] >> b[i];
    }
    if (check(0)) {
        cout << 0 << endl;
        exit(0);
    }
    int l = 0, r = 1e9 + 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
