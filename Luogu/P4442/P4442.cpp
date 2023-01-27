#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505;
const int INF = 0x3f3f3f3f;
const int d[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, s, t, pos[N * N][4], dist1[N][N], dist2[N * N];
std::string h[N];
std::vector<std::pair<int, int>> g[N * N];
bool vis[N * N];

int id(int x, int y) {
    return x * m + y;
}

void spfa() {
    memset(dist2, 0x3f, sizeof(dist2));

    std::queue<int> q;

    q.emplace(s);
    dist2[s] = 0;
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        vis[u] = false;

        for (auto e : g[u]) {
            int v = e.first;
            long long w = e.second;

            if (dist2[v] > dist2[u] + w) {
                dist2[v] = dist2[u] + w;

                if (!vis[v]) {
                    vis[v] = true;

                    q.emplace(v);
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dist1, 0x3f, sizeof(dist1));

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];

        h[i] = ' ' + h[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (h[i][j] == 'C') {
                s = id(i, j);
            } else if (h[i][j] == 'F') {
                t = id(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (h[i][j - 1] == '#') {
                pos[id(i, j)][0] = id(i, j);
            } else {
                pos[id(i, j)][0] = pos[id(i, j - 1)][0];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j; j--) {
            if (h[i][j + 1] == '#') {
                pos[id(i, j)][1] = id(i, j);
            } else {
                pos[id(i, j)][1] = pos[id(i, j + 1)][1];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (h[i - 1][j] == '#') {
                pos[id(i, j)][2] = id(i, j);
            } else {
                pos[id(i, j)][2] = pos[id(i - 1, j)][2];
            }
        }
    }

    for (int i = n; i; i--) {
        for (int j = 1; j <= m; j++) {
            if (h[i + 1][j] == '#') {
                pos[id(i, j)][3] = id(i, j);
            } else {
                pos[id(i, j)][3] = pos[id(i + 1, j)][3];
            }
        }
    }

    std::queue<std::pair<int, int>> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (h[i][j] == '#') {
                q.emplace(i, j);
                dist1[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first,
            y = q.front().second;
        q.pop();

        for (auto d : d) {
            int xx = x + d[0],
                yy = y + d[1];

            if (xx < 1 || xx > n || yy < 1 || yy > m || h[xx][yy] == '#') continue;

            if (dist1[xx][yy] > dist1[x][y] + 1) {
                dist1[xx][yy] = dist1[x][y] + 1;

                q.emplace(xx, yy);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (h[i][j] == '#') continue;

            for (auto d : d) {
                int x = i + d[0],
                    y = j + d[1];

                if (h[x][y] != '#') {
                    g[id(i, j)].emplace_back(id(x, y), 1);
                }
            }

            for (int k = 0; k < 4; k++) {
                if (pos[id(i, j)][k] != id(i, j)) {
                    g[id(i, j)].emplace_back(pos[id(i, j)][k], dist1[i][j]);
                }
            }
        }
    }

    spfa();

    if (dist2[t] == INF) {
        cout << "nemoguce" << endl;
    } else {
        cout << dist2[t] << endl;
    }

    return 0;
}
