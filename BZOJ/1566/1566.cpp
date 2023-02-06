#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505;
const int mod = 1024523;

int n, m, f[2][N][N]{1};
std::string a, b;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> a >> b;

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    a = ' ' + a;
    b = ' ' + b;

    for (int k = 1; k <= n + m; k++) {
        int t = k & 1,
            p = t ^ 1;

        memset(f[t], 0x00, sizeof(f[t]));

        for (int i = std::max(0, k - m); i <= std::min(n, k); i++) {
            for (int j = std::max(0, k - m); j <= std::min(n, k); j++) {
                if (i && j && a[i] == a[j]) {
                    f[t][i][j] = (f[t][i][j] + f[p][i - 1][j - 1]) % mod;
                }

                if (i && k - j && a[i] == b[k - j]) {
                    f[t][i][j] = (f[t][i][j] + f[p][i - 1][j]) % mod;
                }

                if (k - i && j && b[k - i] == a[j]) {
                    f[t][i][j] = (f[t][i][j] + f[p][i][j - 1]) % mod;
                }

                if (k - i && k - j && b[k - i] == b[k - j]) {
                    f[t][i][j] = (f[t][i][j] + f[p][i][j]) % mod;
                }
            }
        }
    }

    cout << f[(n + m) & 1][n][n] << endl;

    return 0;
}
