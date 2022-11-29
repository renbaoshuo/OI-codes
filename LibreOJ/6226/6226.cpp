#include <iostream>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205,
          M = N * N;
const int INF = 0x3f3f3f3f;
const int d[][2]{{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

int n, m, s, t;
int idx, head[M << 1], ver[M << 4], edge[M << 4], next[M << 4];
int dis[M << 1], cur[M << 1];
bool g[N][N];

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

int id(int x, int y) {
    return x * n + y;
}

bool bfs() {
    std::fill_n(dis, M << 1, 0);

    std::queue<int> q;

    q.emplace(s);
    dis[s] = 1;
    cur[s] = head[s];

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                w = edge[i];

            if (w && !dis[v]) {
                dis[v] = dis[u] + 1;
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

        if (w && dis[v] == dis[u] + 1) {
            int k = dinic(v, std::min(w, limit - flow));

            if (!k) dis[v] = 0;

            edge[i] -= k;
            edge[i ^ 1] += k;
            flow += k;
        }
    }

    return flow;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill_n(head, M << 1, -1);

    cin >> n >> m;

    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;

        g[x][y] = true;
    }

    s = 0, t = id(n, n) + 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j]) continue;

            if ((i + j) % 2) {
                add(s, id(i, j), 1);
                add(id(i, j), s, 0);

                for (auto d : d) {
                    int x = i + d[0],
                        y = j + d[1];

                    if (x < 1 || x > n || y < 1 || y > n || g[x][y]) continue;

                    add(id(i, j), id(x, y), INF);
                    add(id(x, y), id(i, j), 0);
                }
            } else {
                add(id(i, j), t, 1);
                add(t, id(i, j), 0);
            }
        }
    }

    int ans = 0, flow;

    while (bfs()) {
        while (flow = dinic(s, INF)) ans += flow;
    }

    std::cerr << ans << endl;

    cout << n * n - m - ans << endl;

    return 0;
}
