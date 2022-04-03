#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, g[N][N], f[N][N], ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = std::max(f[i - 1][j], f[i - 1][j - 1]) + g[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, f[n][i]);
    }

    cout << ans << endl;

    return 0;
}
