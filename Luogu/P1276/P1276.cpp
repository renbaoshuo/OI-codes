#include <bits/stdc++.h>

using namespace std;

int l, n, op, x, y, ans1, ans2, a[10005], b[10005];

int main() {
    cin >> l >> n;
    for (int i = 0; i <= l; i++) {
        a[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> op >> x >> y;
        if (op == 0) {
            for (int j = x; j <= y; j++) {
                if (a[j]) a[j] = 0;
            }
        } else if (op == 1) {
            for (int j = x; j <= y; j++) {
                if (!a[j]) {
                    a[j] = 1;
                    b[j]++;
                }
            }
        }
    }
    for (int i = 0; i <= l; i++) {
        if (b[i] && a[i]) ans1++;
        if (b[i] - a[i] > 0) {
            ans2 += b[i] - a[i];
        }
    }
    cout << ans1 << endl
         << ans2 << endl;
    return 0;
}
