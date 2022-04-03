#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205;

int m, n, w[N], c[N], f[N][N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j; j--) {
            f[i][j] = std::max(f[i - 1][j], j - w[i] >= 0 ? f[i - 1][j - w[i]] + c[i] : -1);
        }
    }

    cout << f[n][m] << endl;

    return 0;
}
