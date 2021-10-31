#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 3 == 2) {
            cout << n / 3 << ' ' << n / 3 + 1 << endl;
        } else if (n % 3 == 1) {
            cout << n / 3 + 1 << ' ' << n / 3 << endl;
        } else {
            cout << n / 3 << ' ' << n / 3 << endl;
        }
    }
    return 0;
}
