#include <bits/stdc++.h>

using namespace std;

int n;
double p, a[100005], b[100005];
double sum, l, r = 1e10, mid;

bool check(double mid) {
    double q = mid * p;
    sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] * mid > b[i]) {
            sum += a[i] * mid - b[i];
        }
    }
    return sum <= q;
}

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if (sum <= p) {
        cout << -1 << endl;
        return 0;
    }
    while (r - l > 1e-6) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(10) << l << endl;
    return 0;
}
