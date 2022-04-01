#include <bits/stdc++.h>

using namespace std;

int t, x, y;

int main() {
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x > y) {
            cout << x + y << endl;
        } else if (x == y) {
            cout << x << endl;
        } else {
            cout << y - (y % x / 2) << endl;
        }
    }
    return 0;
}
