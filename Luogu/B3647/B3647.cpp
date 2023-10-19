#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, m, f[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    memset(f, 0x3f, sizeof(f));

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        f[u][v] = f[v][u] = w;
    }

    for (int i = 1; i <= n; i++) {
        f[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j] << ' ';
        }

        cout << endl;
    }

    return 0;
}
