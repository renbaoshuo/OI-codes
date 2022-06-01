#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105,
          M = 1e6 + 5;

int n, m, v[N], s[N], g[M];
bool f[M];

int main() {
    std::ios::sync_with_stdio(false);

    while (cin >> n >> m, n || m) {
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }

        memset(f, 0x00, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            memset(g, 0x00, sizeof(g));
            for (int j = v[i]; j <= m; j++) {
                if (!f[j] && f[j - v[i]] && g[j - v[i]] < s[i]) {
                    f[j] = true;
                    g[j] = g[j - v[i]] + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= m; i++) ans += f[i];
        cout << ans << endl;
    }
    return 0;
}
