#include <iostream>
#include <cstring>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, m, s[N], v[N][N], w[N][N], f[N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j++) {
            cin >> v[i][j] >> w[i][j];
        }
    }

    memset(f, 0xcf, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= s[i]; k++) {
                if (j >= v[i][k]) {
                    f[j] = std::max(f[j], f[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }

    cout << f[m] << endl;

    return 0;
}
