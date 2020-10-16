#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, sum = 0, ans = 1, t;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (sum + t > m) {
            ans++;
            sum = t;
        }
        else {
            sum += t;
        }
    }
    cout << ans << endl;
    return 0;
}
