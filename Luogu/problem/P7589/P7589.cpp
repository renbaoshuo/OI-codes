#include <bits/stdc++.h>

using namespace std;

int t, n, k, d, y, b, w, r;

int main() {
    cin >> t;
    while (t--) {
        r = 0;
        cin >> n >> k >> d;
        while (n--) {
            cin >> y >> b >> w;
            r ^= abs(b - w) - 1;
        }
        cout << (r ? "Yes" : "No") << endl;
    }
    return 0;
}
