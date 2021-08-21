#include <bits/stdc++.h>

using namespace std;

int t;
long long l, r, c;

int main() {
    cin >> t;
    while (t--) {
        cin >> l >> r;
        c = (r - l + 1) % 9;
        cout << (c * (l % 9) % 9 + c * (c - 1) % 9 * 5 % 9) % 9 << endl;
    }
    return 0;
}
