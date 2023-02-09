#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, k, t;
long long x[N], a[N];

bool check(int v) {
    for (int i = 1; i <= n; i++) {
        a[i] = x[i] - 2ll * v * t * i;
    }

    if (a[n] > a[1]) {
        return false;
    }

    int l = k, r = k;

    for (int i = k - 1; i >= 1; i--) {
        if (a[l] - a[i] <= 0) l = i;
    }

    for (int i = k + 1; i <= n; i++) {
        if (a[i] - a[r] <= 0) r = i;
    }

    int l1 = k, r1 = k;

    while (l < l1 || r1 < r) {
        int nl = l1, nr = r1;
        bool flag = false;

        while (l < nl && a[r1] - a[nl - 1] <= 0) {
            if (a[l1] - a[--nl] <= 0) break;
        }

        if (nl < l1 && a[l1] - a[nl] <= 0) {
            l1 = nl;
            flag = true;
        }

        while (nr < r && a[nr + 1] - a[l1] <= 0) {
            if (a[++nr] - a[r1] <= 0) break;
        }

        if (r1 < nr && a[nr] - a[r1] <= 0) {
            r1 = nr;
            flag = true;
        }

        if (!flag) return false;
    }

    int l2 = 1, r2 = n;

    while (l2 < l || r < r2) {
        int nl = l2, nr = r2;
        bool flag = false;

        while (nl < l && a[r2] - a[nl + 1] <= 0) {
            if (a[++nl] - a[l2] >= 0) break;
        }

        if (l2 < nl && a[nl] - a[l2] >= 0) {
            l2 = nl;
            flag = true;
        }

        while (r < nr && a[nr - 1] - a[l2] <= 0) {
            if (a[r2] - a[--nr] >= 0) break;
        }

        if (nr < r2 && a[r2] - a[nr] >= 0) {
            r2 = nr;
            flag = true;
        }

        if (!flag) return false;
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> t;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    int l = 0, r = 1e9,
        res = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (check(mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << res << endl;

    return 0;
}
