#include <iostream>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
#define endl '\n'

int n, m, q, f[15][15];
char s[1005][15], qs[15];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] + 1;
    }
    while (m--) {
        int ans = 0;
        cin >> qs + 1 >> q;
        for (int k = 1; k <= n; k++) {
            memset(f, 0x00, sizeof(f));
            int n = strlen(s[k] + 1),
                m = strlen(qs + 1);
            for (int i = 1; i <= n; i++) {
                f[i][0] = i;
            }
            for (int i = 1; i <= m; i++) {
                f[0][i] = i;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    f[i][j] = std::min({f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + (s[k][i] != qs[j])});
                }
            }
            if (f[n][m] <= q) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
