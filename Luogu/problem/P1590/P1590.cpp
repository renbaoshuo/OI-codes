#include <bits/stdc++.h>

using namespace std;

long long t, n, m, ans;

int main() {
    cin >> t;
    while (t--) {
        ans = m = 0;
        cin >> n;
        while (n) {
            ans += (n % 10 - (n % 10 > 7)) * pow(9, m++);
            n /= 10;
        }
        cout << ans << endl;
    }
    return 0;
}
