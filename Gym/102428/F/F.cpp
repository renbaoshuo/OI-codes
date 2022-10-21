#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e3 + 5;
const int mod = 1e9 + 7;

int m, n, f[N][N], s[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    for (int i = m; i <= n; i++) {
        f[1][i] = 1;
        s[i] = 1;
    }

    for (int i = 2; i <= m; i++) {
        f[i][m] = 1;
        s[i + m]++;

        for (int j = m + 1; j <= n; j++) {
            f[i][j] = (f[i - 1][j] + s[j]) % mod;
            s[i + j] = (s[i + j] + f[i][j]) % mod;
        }
    }

    cout << f[m][n] << endl;

    return 0;
}
