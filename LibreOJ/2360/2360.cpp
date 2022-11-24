#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005,
          V = 305;

int n, m, v, e, c[N], d[N], g[V][V];
double p[N], f[N][N][2], ans = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> v >> e;

    memset(g, 0x3f, sizeof(g));

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= v; i++) {
        g[i][i] = 0;
    }

    for (int i = 1, a, b, w; i <= e; i++) {
        cin >> a >> b >> w;

        g[a][b] = g[b][a] = std::min(g[a][b], w);
    }

    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j][0] = f[i][j][1] = 1e9;
        }
    }

    f[1][0][0] = f[1][1][1] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= std::min(m, i); j++) {
            f[i][j][0] = std::min(
                f[i - 1][j][0]
                    + g[c[i - 1]][c[i]],
                f[i - 1][j][1]
                    + p[i - 1] * g[d[i - 1]][c[i]]
                    + (1.0 - p[i - 1]) * g[c[i - 1]][c[i]]);

            if (j) {
                f[i][j][1] = std::min(
                    f[i - 1][j - 1][0]
                        + p[i] * g[c[i - 1]][d[i]]
                        + (1.0 - p[i]) * g[c[i - 1]][c[i]],
                    f[i - 1][j - 1][1]
                        + p[i - 1] * p[i] * g[d[i - 1]][d[i]]
                        + (1.0 - p[i - 1]) * p[i] * g[c[i - 1]][d[i]]
                        + p[i - 1] * (1.0 - p[i]) * g[d[i - 1]][c[i]]
                        + (1.0 - p[i - 1]) * (1.0 - p[i]) * g[c[i - 1]][c[i]]);
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        ans = std::min({ans, f[n][i][0], f[n][i][1]});
    }

    cout << std::fixed << std::setprecision(2) << ans << endl;

    return 0;
}
