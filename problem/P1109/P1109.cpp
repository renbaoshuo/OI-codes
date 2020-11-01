#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a[55], l, r;
    int p = 0, q = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> l >> r;
    for (int i = 0; i < n; i++) {
        if (a[i] > r) {
            p += a[i] - r;
        }
        else if (a[i] < l) {
            q += l - a[i];
        }
    }
    if (n * r < sum) {
        cout << -1 << endl;
    }
    else {
        cout << max(p, q) << endl;
    }
    return 0;
}
