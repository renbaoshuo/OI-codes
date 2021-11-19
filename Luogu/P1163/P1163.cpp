#include <bits/stdc++.h>

using namespace std;

int main() {
    double n, m, k, l, r, mid;
    cin >> n >> m >> k;
    l = 00.0;
    r = 10.0;
    while (r - l >= 0.0001) {
        mid = (l + r) / 2;
        if (pow(1.0 / (1.0 + mid), k) >= 1 - n / m * mid) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(1) << l * 100 << endl;
    return 0;
}
