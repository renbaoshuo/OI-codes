#include <bits/stdc++.h>

using namespace std;

int n, q, r, c, l;
long long s, s0[1005][1005], s1[1005][1005], s2[1005][1005], ans;

int main() {
    cin >> n >> q;
    while (q--) {
        cin >> r >> c >> l >> s;
        s1[r][c] += s;
        if (r + l <= n) {
            s1[r + l][c] -= s;
        }
        s2[r][c + 1] -= s;
        if (r + l <= n && c + l + 1 <= n) {
            s2[r + l][c + l + 1] += s;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s1[i][j] += s1[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s2[i][j] += s2[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s0[i][j] = s0[i][j - 1] + s1[i][j] + s2[i][j];
            ans ^= s0[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
