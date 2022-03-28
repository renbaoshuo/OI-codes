#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105,
          mod = 1e6 + 7;

int n, m, a[N], f[N][N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++) {
        f[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= a[i]; j++) {
            for (int k = 0; k <= m - j; k++) {
                if (j || k) {
                    f[i][j + k] = (f[i][j + k] + f[i - 1][k]) % mod;
                }
            }
        }
    }

    cout << f[n][m] % mod << endl;

    return 0;
}
