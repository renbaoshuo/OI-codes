#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, l = 0, q = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < q) {
            l = 1;
        }
        if (t > q && l == 1) {
            l = 0;
            ans++;
        }
        q = t;
    }
    cout << ans << endl;
    return 0;
}
