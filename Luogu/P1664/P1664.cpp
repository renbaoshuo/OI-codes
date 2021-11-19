#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d = 0, ans = 0, m = 0, now;
    cin >> n;
    while (n--) {
        cin >> now;
        if (now) {
            if (m > 0) {
                d -= pow(2, m - 1);
            }
            if (d < 0) {
                d = 0;
            }
            ans++;
            d++;
            m = 0;
            if (d >= 3) {
                ans++;
            }
            if (d >= 7) {
                ans++;
            }
            if (d >= 30) {
                ans++;
            }
            if (d >= 120) {
                ans++;
            }
            if (d >= 365) {
                ans++;
            }
        } else {
            m++;
        }
    }
    cout << ans << endl;
    return 0;
}
