#include <bits/stdc++.h>

using namespace std;

int t, n, a[10005], b[10005], c[10005];

double f(double x, int i) {
    return x * x * a[i] + x * b[i] + c[i];
}

double check(double x) {
    double ans = f(x, 1);
    for (int i = 2; i <= n; i++) {
        ans = max(ans, f(x, i));
    }
    return ans;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        double l = 0.00, r = 1000.00, mid1, mid2;
        while (r - l > 1e-11) {
            mid1 = l + (r - l) / 3.0;
            mid2 = r - (r - l) / 3.0;
            if (check(mid1) > check(mid2)) {
                l = mid1;
            }
            else {
                r = mid2;
            }
        }
        cout << fixed << setprecision(4) << check(l) << endl;
    }
    return 0;
}
