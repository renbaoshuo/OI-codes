#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55 * 55 * 2,
          M = N * N;
const int INF = 0x3f3f3f3f;

int n, m, s, t, a[55][55], flow, res, ans;
int idx, head[N], ver[M << 1], edge[M << 1], next[M << 1];
int dis[N], cur[N];

int id(int x, int y, int k) {
    return k * n * m + x * m + y;
}

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

bool bfs() {
    std::fill(std::begin(dis), std::end(dis), 0);

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

    cin >> n >> m;

    s = 0, t = id(n, m, 1) + 1;
    std::fill(std::begin(head), std::end(head), -1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];

            add(id(i, j, 0), id(i, j, 1), INF);
            add(id(i, j, 1), id(i, j, 0), 0);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int max = 0;

            if (a[i][j] == -1) {
                add(s, id(i, j, 0), INF);
                add(id(i, j, 0), s, 0);

                for (int k = i; k >= 1; k--) {
                    max = std::max(max, a[k][j]);
                }

                for (int k = i; k > 1; k--) {
                    add(id(k, j, 0), id(k - 1, j, 0), max - std::max(a[k][j], 0));
                    add(id(k - 1, j, 0), id(k, j, 0), 0);
                }
            } else if (a[i][j] == -2) {
                add(s, id(i, j, 0), INF);
                add(id(i, j, 0), s, 0);

                for (int k = i; k <= n; k++) {
                    max = std::max(max, a[k][j]);
                }

                for (int k = i; k < n; k++) {
                    add(id(k, j, 0), id(k + 1, j, 0), max - std::max(a[k][j], 0));
                    add(id(k + 1, j, 0), id(k, j, 0), 0);
                }
            } else if (a[i][j] == -3) {
                add(id(i, j, 1), t, INF);
                add(t, id(i, j, 1), 0);

                for (int k = 1; k <= j; k++) {
                    max = std::max(max, a[i][k]);
                }

                for (int k = 1; k < j; k++) {
                    add(id(i, k, 1), id(i, k + 1, 1), max - std::max(a[i][k + 1], 0));
                    add(id(i, k + 1, 1), id(i, k, 1), 0);
                }
            } else if (a[i][j] == -4) {
                add(id(i, j, 1), t, INF);
                add(t, id(i, j, 1), 0);

                for (int k = m; k >= j; k--) {
                    max = std::max(max, a[i][k]);
                }

                for (int k = m; k > j; k--) {
                    add(id(i, k, 1), id(i, k - 1, 1), max - std::max(a[i][k - 1], 0));
                    add(id(i, k - 1, 1), id(i, k, 1), 0);
                }
            }

            ans += max;
        }
    }

    while (bfs()) {
        while (flow = dinic(s, INF)) res += flow;
    }

    cout << ans - res << endl;

    return 0;
}
