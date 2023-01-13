#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105,
          M = N * N * 2;
const int INF = 0x3f3f3f3f;

const int d[][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct DSU : private std::vector<int> {
    DSU(const int& _n)
        : std::vector<int>(_n + 1) {
        std::iota(begin(), end(), 0);
    }

    int find(const int& x) {
        return x == at(x) ? x : at(x) = find(at(x));
    }

    bool check(const int& x, const int& y) {
        return find(x) == find(y);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) at(y) = x;
    }
};

int n, m, s, t, cnt, a[N * N], b[N * N], c[N * N];
int idx, head[N * N], ver[M], edge[M], next[M];
int cur[N * N], dist[N * N];
bool g1[N][N], g2[N][N], vis[N][N], color[N * N];
std::unordered_set<int> g[N * N];

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

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill(std::begin(head), std::end(head), -1);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;

            cin >> c;

            g1[i][j] = c - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;

            cin >> c;

            g2[i][j] = c - '0';
        }
    }

    DSU dsu(n * m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j]) continue;

            std::queue<std::pair<int, int>> q;

            q.emplace(i, j);
            color[c[id(i, j)] = ++cnt] = g1[i][j];
            vis[i][j] = true;

            while (!q.empty()) {
                int x = q.front().first,
                    y = q.front().second;
                q.pop();

                if (g1[i][j] != g2[x][y]) a[cnt]++;
                else b[cnt]++;

                for (auto d : d) {
                    int xx = x + d[0],
                        yy = y + d[1];

                    if (xx < 1 || xx > n || yy < 1 || yy > m || g1[x][y] != g1[xx][yy] || vis[xx][yy]) continue;

                    q.emplace(xx, yy);
                    vis[xx][yy] = true;
                    dsu.merge(id(i, j), id(xx, yy));
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (auto d : d) {
                int xx = i + d[0],
                    yy = j + d[1];

                if (xx < 1 || xx > n || yy < 1 || yy > m || g1[i][j] == g1[xx][yy]) continue;

                int u = c[dsu.find(id(i, j))],
                    v = c[dsu.find(id(xx, yy))];

                g[u].emplace(v);
                g[v].emplace(u);
            }
        }
    }

    s = 0, t = cnt + 1;

    for (int i = 1; i <= cnt; i++) {
        if (color[i] == 0) {
            add(s, i, a[i]);
            add(i, s, 0);

            add(i, t, b[i]);
            add(t, i, 0);

            for (int v : g[i]) {
                add(i, v, INF);
                add(v, i, 0);
            }
        } else {
            add(s, i, b[i]);
            add(i, s, 0);

            add(i, t, a[i]);
            add(t, i, 0);
        }
    }

    int res = 0;

    while (bfs()) {
        while (int flow = dinic(s, INF)) res += flow;
    }

    cout << res << endl;

    return 0;
}
