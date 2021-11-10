#include <bits/stdc++.h>

using namespace std;

int t, r, c, w[1005][1005], f[1005][1005];

int main() {
    cin >> t;
    while (t--) {
        memset(w, 0x00, sizeof(w));
        memset(f, 0x00, sizeof(f));
        cin >> r >> c;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> w[i][j];
            }
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]) + w[i][j];
            }
        }
        cout << f[r][c] << endl;
    }
    return 0;
}
