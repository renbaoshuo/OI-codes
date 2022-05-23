#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int n, m, l, r, w[200005], v[200005];
long long s, y, sum, ans, fn[200005], fv[200005];
std::pair<int, int> q[200005];

bool check(int x) {
    y = sum = 0;
    memset(fn, 0x00, sizeof(fn));
    memset(fv, 0x00, sizeof(fv));
    for (int i = 1; i <= n; i++) {
        if (w[i] >= x) {
            fn[i] = fn[i - 1] + 1;
            fv[i] = fv[i - 1] + v[i];
        } else {
            fn[i] = fn[i - 1];
            fv[i] = fv[i - 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        y += (fn[q[i].second] - fn[q[i].first - 1]) * (fv[q[i].second] - fv[q[i].first - 1]);
    }
    sum = std::abs(y - s);
    return y > s;
}

int main() {
    ans = std::numeric_limits<long long>::max();
    l = std::numeric_limits<int>::max();
    r = std::numeric_limits<int>::min();
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        l = std::min(l, w[i]);
        r = std::max(r, w[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> q[i].first >> q[i].second;
    }
    l -= 1, r += 2;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        ans = std::min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
