#include <bits/stdc++.h>

using namespace std;

int t, a, b, c, d, k, x, y;

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> k;
        try {
            x = ceil(1.0 * a / c);
            y = ceil(1.0 * b / d);
            if (x + y > k) {
                throw "No answer";
            }
            cout << x << ' ' << y << endl;
        } catch (...) {
            cout << -1 << endl;
        }
    }
    return 0;
}
