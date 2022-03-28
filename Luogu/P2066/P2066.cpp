#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 15,
          M = 20;

int n, m, w[N][M], f[N][M], g[N][M];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 0; j--) {
            f[i][j] = f[i + 1][j];
            for (int k = 1; k <= j; k++) {
                if (f[i][j] < f[i + 1][j - k] + w[i][k]) {
                    f[i][j] = f[i + 1][j - k] + w[i][k];
                    g[i][j] = k;
                }
            }
        }
    }

    cout << f[1][m] << endl;

    for (int i = 1, j = m; i <= n; i++) {
        cout << i << ' ' << g[i][j] << endl;
        j -= g[i][j];
    }

    return 0;
}
