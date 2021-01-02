#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-11;
int n;
double l, r, a[20], mid1, mid2;

double f(double x) {
    double s = 0;
    for (int i = n; i >= 0; i--) {
        s = s * x + a[i];
    }
    return s;
}

int main() {
    cin >> n >> l >> r;
    for (int i = n; i >= 0; i--) {
        cin >> a[i];
    }
    while (r - l >= eps) {
        mid1 = l + (r - l) / 3.0;
        mid2 = r - (r - l) / 3.0;
        if (f(mid1) > f(mid2)) {
            r = mid2;
        }
        else {
            l = mid1;
        }
    }
    cout << fixed << setprecision(5) << l << endl;
    return 0;
}
