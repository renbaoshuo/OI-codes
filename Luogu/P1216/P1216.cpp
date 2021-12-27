#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

const int N = 1005;

int r, g[N][N], f[N][N], ans = std::numeric_limits<int>::min();

int main() {
    cin >> r;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> g[i][j];
        }
    }
    f[1][1] = g[1][1];
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i + 1; j++) {
            f[i][j] = std::max(f[i - 1][j - 1], f[i - 1][j]) + g[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        ans = std::max(ans, f[r][i]);
    }
    cout << ans << endl;
    return 0;
}
