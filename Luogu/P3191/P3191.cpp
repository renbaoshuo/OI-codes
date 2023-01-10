#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 25,
          M = N * N,
          E = 3e5 + 5;
const int INF = 0x3f3f3f3f;

const int d[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int n, m, s, t, cnt, f[M][M];
char g[N][N];
int idx, head[E], ver[E << 1], edge[E << 1], next[E << 1];
int cur[E << 1], dist[E << 1];
bool vis[E << 1], vis2[M][M];

int id(int x, int y) {
    return (x - 1) * m + y;
}

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

bool bfs() {
    std::fill(std::begin(dist), std::end(dist), 0);

    std::queue<int> q;

    q.emplace(s);
    dist[s] = 1;
    cur[s] = head[s];

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                w = edge[i];

            if (!dist[v] && w) {
                dist[v] = dist[u] + 1;
                cur[v] = head[v];

                if (v == t) return true;

                q.emplace(v);
            }
        }
    }

    return false;
}

int dinic(int u, int limit) {
    if (u == t) return limit;

    int flow = 0;

    for (int i = cur[u]; ~i && flow < limit; i = next[i]) {
        cur[u] = i;

        int v = ver[i],
            w = edge[i];

        if (dist[v] == dist[u] + 1 && w) {
            int k = dinic(v, std::min(w, limit - flow));

            if (!k) dist[v] = 0;

            edge[i] -= k;
            edge[i ^ 1] += k;
            flow += k;
        }
    }

    return flow;
}

bool check(int x) {
    idx = 0;
    std::fill(std::begin(head), std::end(head), -1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '.') {
                add(s, id(i, j), 1);
                add(id(i, j), s, 0);
            } else if (g[i][j] == 'D') {
                for (int k = 0; k < x; k++) {
                    add(n * m + id(i, j) * x + k, t, 1);
                    add(t, n * m + id(i, j) * x + k, 0);
                }

                for (int k = 0; k < x - 1; k++) {
                    add(n * m + id(i, j) * x + k, n * m + id(i, j) * x + k + 1, INF);
                    add(n * m + id(i, j) * x + k + 1, n * m + id(i, j) * x + k, 0);
                }

                for (int p = 1; p <= n; p++) {
                    for (int q = 1; q <= m; q++) {
                        if (g[p][q] == '.') {
                            int d = f[id(p, q)][id(i, j)];

                            if (d <= x) {
                                add(id(p, q), n * m + id(i, j) * x + d - 1, INF);
                                add(n * m + id(i, j) * x + d - 1, id(p, q), 0);
                            }
                        }
                    }
                }
            }
        }
    }

    int res = 0;

    while (bfs()) {
        while (int flow = dinic(s, INF)) res += flow;
    }

    return res == cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(f, 0x3f, sizeof(f));

    cin >> n >> m;

    s = 0, t = 10000;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];

            if (g[i][j] == '.') cnt++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'D') {
                memset(vis2, 0x00, sizeof(vis2));

                f[id(i, j)][id(i, j)] = 0;

                std::queue<std::pair<int, int>> q;

                q.emplace(i, j);

                while (!q.empty()) {
                    int x = q.front().first,
                        y = q.front().second;
                    q.pop();

                    for (auto d : d) {
                        int xx = x + d[0],
                            yy = y + d[1];

                        if (xx < 0 || xx > n || yy < 0 || yy > m || g[xx][yy] != '.' || vis2[xx][yy]) continue;

                        vis2[xx][yy] = true;

                        if (f[id(xx, yy)][id(i, j)] > f[id(x, y)][id(i, j)] + 1) {
                            f[id(xx, yy)][id(i, j)] = f[id(x, y)][id(i, j)] + 1;

                            q.emplace(xx, yy);
                        }
                    }
                }
            }
        }
    }

    int l = 0,
        r = cnt,
        res = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (check(mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    if (res == -1) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}
