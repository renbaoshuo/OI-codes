#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3005;
const int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m, k, q, id[N][N], dist[N][N], ans;
std::queue<std::pair<int, int>> queue;
bool g[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dist, -0x3f, sizeof(dist));

    cin >> n >> m >> k;

    for (int i = 1, x, y; i <= k; i++) {
        cin >> x >> y;

        id[x][y] = i;
        dist[x][y] = 0;

        queue.emplace(x, y);
    }

    cin >> q;

    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;

        g[x][y] = true;
    }

    while (!queue.empty()) {
        int x, y;

        std::tie(x, y) = queue.front();
        queue.pop();

        for (const auto &d : d) {
            int xx = x + d[0],
                yy = y + d[1];

            if (xx < 1 || xx > n || yy < 1 || yy > m || g[xx][yy]) continue;

            if (id[xx][yy] == 0) {
                id[xx][yy] = id[x][y];
                dist[xx][yy] = dist[x][y] + 1;

                queue.emplace(xx, yy);
            } else if (dist[x][y] + 1 == dist[xx][yy] && id[x][y] != id[xx][yy]) {
                id[xx][yy] = -1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (id[i][j] == -1) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
