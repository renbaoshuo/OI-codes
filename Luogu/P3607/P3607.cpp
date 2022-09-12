#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55;

int n, a[N], f[N][N][N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= a[l]; i++) {
            for (int j = a[l]; j <= 50; j++) {
                f[l][l][i][j] = 1;
            }
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = len; r <= n; l++, r++) {
            for (int i = 1; i <= 50; i++) {
                for (int j = i; j <= 50; j++) {
                    f[l][r][i][j] = std::max({
                        f[l][r][i][j],
                        f[l + 1][r][i][j] + (a[l] == i),
                        f[l][r - 1][i][j] + (a[r] == j),
                        f[l + 1][r - 1][i][j] + (a[r] == i) + (a[l] == j),
                    });

                    f[l][r][i][j + 1] = std::max(f[l][r][i][j + 1], f[l][r][i][j]);
                    f[l][r][i - 1][j] = std::max(f[l][r][i - 1][j], f[l][r][i][j]);
                }
            }

            for (int j = 1; j <= 50; j++) {
                for (int i = j; i; i--) {
                    f[l][r][i - 1][j] = std::max(f[l][r][i - 1][j], f[l][r][i][j]);
                }
            }
        }
    }

    cout << f[1][n][1][50] << endl;

    return 0;
}
