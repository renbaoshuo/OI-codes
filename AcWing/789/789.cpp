#include <bits/stdc++.h>

using namespace std;

int n, q, t, k, a[100005];

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> k;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (a[l] != k) {
            cout << -1 << ' ' << -1 << endl;
            continue;
        }
        cout << l << ' ';
        l = 0;
        r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (a[mid] <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << l << endl;
    }
    return 0;
}
