#include <bits/stdc++.h>

using namespace std;

int t, n, m, ans;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ans = (n * m) / 3;
        cout << ans + !(n % 3 == 0 || m % 3 == 0) << endl;
    }
    return 0;
}
