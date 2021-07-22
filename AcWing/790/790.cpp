#include <bits/stdc++.h>

using namespace std;

double n, l, r;

int main() {
    cin >> n;
    l = -100.00;
    r = 100.00;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(6) << l << endl;
    return 0;
}
