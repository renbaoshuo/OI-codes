#include <bits/stdc++.h>

using namespace std;

int n, m, a[100005], maxa, f[100005], l, r, mid;

bool check(int x) {
    int cnt = 0, ch = 0;
    for (int i = 1; i < n; i++) {
        ch += f[i];
        if (ch >= x) {
            cnt++;
            ch = 0;
        }
    }
    return cnt >= m - 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++) {
        f[i] = a[i + 1] - a[i];
    }
    l = 1;
    r = maxa;
    while (l <= r) {
        mid = l + r >> 1;
        if (r - l == 1) {
            if (check(r)) l = r;
            break;
        }
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
