#include <bits/stdc++.h>

using namespace std;

int t;
long long n, s;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        if (s) {
            cout << (n + 1 >> 1) << endl;
        } else if (n & 1) {
            cout << (n >> 1) << endl;
        } else {
            for (int i = 1; i <= 30; i++) {
                if ((1ll << (i - 1)) <= n && n < (1ll << i)) {
                    cout << ((n - (1ll << i - 1)) >> 1) << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
