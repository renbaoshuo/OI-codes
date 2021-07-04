#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, l = 0, ans = 0;
    cin >> n;
    while (n--) {
        cin >> t;
        if (t > l) {
            ans += t - l;
        }
        l = t;
    }
    cout << ans << endl;
    return 0;
}
