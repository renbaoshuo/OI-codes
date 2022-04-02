#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int t, n, m, g[N][N], f[N][N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        memset(f, 0x00, sizeof(f));

        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = std::max(f[i - 1][j], f[i][j - 1]) + g[i][j];
            }
        }

        cout << f[n][m] << endl;
    }

    return 0;
}
