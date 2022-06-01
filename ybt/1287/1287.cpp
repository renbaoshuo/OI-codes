#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, g[N][N], f[N][N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }

    memset(f, 0x3f, sizeof(f));
    f[0][1] = f[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = std::min(f[i - 1][j], f[i][j - 1]) + g[i][j];
        }
    }

    cout << f[n][n] << endl;

    return 0;
}
