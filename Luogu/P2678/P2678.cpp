#include <bits/stdc++.h>

using namespace std;

int n, m, l, r, mid, ans, a[50005];

bool check(int x) {
    int now = 0, cnt = 0, i = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] - a[now] < x) {
            cnt++;
        } else {
            now = i;
        }
    }
    return cnt <= m;
}

int main() {
    cin >> r >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = r;
    l = 1;
    while (l <= r) {
        mid = l + r >> 1;
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
