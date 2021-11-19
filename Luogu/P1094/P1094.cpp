#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, n, ans = 0, p[30005];
    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);
    int l = 0, r = n - 1;
    while (l <= r) {
        if (p[l] + p[r] <= w) {
            l++;
            r--;
            ans++;
        } else {
            r--;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
