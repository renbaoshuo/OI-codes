#include <bits/stdc++.h>

using namespace std;

int t, n, cnt, l, r, a[1005][6];
bool flag;

int main() {
    cin >> t;
    while (t--) {
        flag = false;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 5; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= 5; i++) {
            for (int j = i + 1; j <= 5; j++) {
                cnt = l = r = 0;
                for (int k = 1; k <= n; k++) {
                    if (a[k][i] == 1 && a[k][j] == 1) {
                        cnt++;
                    } else {
                        l += a[k][i];
                        r += a[k][j];
                    }
                }
                if (cnt + l + r == n && l <= n / 2 && r <= n / 2) {
                    flag = true;
                    break;
                }
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}
