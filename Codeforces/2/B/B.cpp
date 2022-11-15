#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, zx, zy, a[N][N], f[N][N][2];
bool g[N][N][2], flag;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1, x; j <= n; j++) {
            cin >> x;

            if (x == 0) {
                flag = true;
                zx = i, zy = j;

                continue;
            }

            while (x % 2 == 0) {
                x /= 2;
                f[i][j][0]++;
            }

            while (x % 5 == 0) {
                x /= 5;
                f[i][j][1]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // true => D
            // false => R
            if (i > 1 && j > 1) {
                if (f[i - 1][j][0] < f[i][j - 1][0]) {
                    g[i][j][0] = true;
                    f[i][j][0] += f[i - 1][j][0];
                } else {
                    g[i][j][0] = false;
                    f[i][j][0] += f[i][j - 1][0];
                }

                if (f[i - 1][j][1] < f[i][j - 1][1]) {
                    g[i][j][1] = true;
                    f[i][j][1] += f[i - 1][j][1];
                } else {
                    g[i][j][1] = false;
                    f[i][j][1] += f[i][j - 1][1];
                }
            } else if (i > 1) {
                g[i][j][0] = g[i][j][1] = true;
                f[i][j][0] += f[i - 1][j][0];
                f[i][j][1] += f[i - 1][j][1];
            } else if (j > 1) {
                g[i][j][0] = g[i][j][1] = false;
                f[i][j][0] += f[i][j - 1][0];
                f[i][j][1] += f[i][j - 1][1];
            }
        }
    }

    bool p = f[n][n][0] > f[n][n][1];

    if (flag && f[n][n][p]) {
        cout << 1 << endl;

        for (int i = 1; i < zy; i++) {
            cout << "R";
        }

        for (int i = 1; i < n; i++) {
            cout << "D";
        }

        for (int i = zy; i < n; i++) {
            cout << "R";
        }

        cout << endl;

        exit(0);
    }

    int x = n, y = n;
    std::string s;

    cout << f[n][n][p] << endl;

    while (x != 1 || y != 1) {
        if (g[x][y][p]) {
            s.push_back('D');
            x--;
        } else {
            s.push_back('R');
            y--;
        }
    }

    std::reverse(s.begin(), s.end());

    cout << s << endl;

    return 0;
}
