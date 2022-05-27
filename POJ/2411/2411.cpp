#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, m;
long long f[12][1 << 11];
bool g[1 << 11];

int main() {
    std::ios::sync_with_stdio(false);

    while (cin >> n >> m, n || m) {
        for (int i = 0; i < 1 << m; i++) {
            bool cnt = false,
                 has_odd = false;

            for (int j = 0; j < m; j++) {
                if (i >> j & 1) {
                    has_odd |= cnt;
                    cnt = false;
                } else {
                    cnt ^= true;
                }
            }

            g[i] = !(has_odd | cnt);
        }

        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 1 << m; j++) {
                f[i][j] = 0;

                for (int k = 0; k < 1 << m; k++) {
                    if (!(j & k) && g[j | k]) {
                        f[i][j] += f[i - 1][k];
                    }
                }
            }
        }

        cout << f[n][0] << endl;
    }

    return 0;
}
