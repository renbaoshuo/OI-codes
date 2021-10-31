#include <bits/stdc++.h>

using namespace std;

long long t, a, b, c, d, x, y, k;

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        x = abs(a - c);
        y = abs(b - d);
        cout << max(x, y) * 2 - !(x % 2 == 0 && y % 2 == 0 || x % 2 && y % 2) << endl;
    }
    return 0;
}
