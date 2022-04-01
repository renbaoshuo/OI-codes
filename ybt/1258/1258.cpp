#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int r, g[N][N], f[N][N], ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> r;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = std::max(f[i - 1][j - 1], f[i - 1][j]) + g[i][j];
        }
    }

    for (int i = 1; i <= r; i++) {
        ans = std::max(ans, f[r][i]);
    }
    cout << ans << endl;

    return 0;
}
