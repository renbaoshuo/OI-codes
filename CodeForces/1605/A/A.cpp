#include <bits/stdc++.h>

using namespace std;

int t, a1, a2, a3;

int main() {
    cin >> t;
    while (t--) {
        cin >> a1 >> a2 >> a3;
        if ((a1 + a2 + a3) % 3) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
