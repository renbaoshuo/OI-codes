#include <bits/stdc++.h>

using namespace std;

int l, r, n, k, a[100005];

bool check(int mid) {
    int m = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] >= mid) {
            m += (a[i] - a[i - 1]) / mid;
            if ((a[i] - a[i - 1]) % mid == 0) m--;
        }
    }
    return m <= k;
}

int main() {
    cin >> r >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
