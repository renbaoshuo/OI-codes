#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 355,
          M = 125;

int n, m, a[N], b[5], f[M][M][M][M];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1, x; i <= m; i++) {
        cin >> x;
        b[x]++;
    }

    f[0][0][0][0] = a[1];
    for (int i = 0; i <= b[1]; i++) {
        for (int j = 0; j <= b[2]; j++) {
            for (int k = 0; k <= b[3]; k++) {
                for (int l = 0; l <= b[4]; l++) {
                    f[i][j][k][l] = std::max({
                                        i ? f[i - 1][j][k][l] : 0,
                                        j ? f[i][j - 1][k][l] : 0,
                                        k ? f[i][j][k - 1][l] : 0,
                                        l ? f[i][j][k][l - 1] : 0,
                                    }) +
                                    a[1 + i + j * 2 + k * 3 + l * 4];
                }
            }
        }
    }

    cout << f[b[1]][b[2]][b[3]][b[4]] << endl;

    return 0;
}
