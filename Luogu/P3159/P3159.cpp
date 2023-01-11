#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 25,
          M = N * N * 8;
const int INF = 0x3f3f3f3f;

const int d[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

int n, m, s, t, cnt, cnt1, cnt2, cost;
bool g1[N][N], g2[N][N];
int idx, head[M], ver[M << 1], next[M << 1];
std::pair<int, int> edge[M << 1];
int dist[M];
bool vis[M];

int id(int x, int y, int k = 0) {
    return n * m * k + (x - 1) * m + y;
}

void add(int u, int v, int c, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = std::make_pair(c, w);
    head[u] = idx++;
}

bool spfa() {
    std::fill(std::begin(vis), std::end(vis), false);
    std::fill(std::begin(dist), std::end(dist), INF);

    std::queue<int> q;

    q.emplace(s);
    dist[s] = 0;
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        vis[u] = false;

        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                c = edge[i].first,
                w = edge[i].second;

            if (c > 0 && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;

                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    return dist[t] != INF;
}

int dinic(int u, int limit) {
    if (u == t) return limit;

    int flow = 0;

    vis[u] = true;

    for (int i = head[u]; ~i && flow < limit; i = next[i]) {
        int v = ver[i],
            c = edge[i].first,
            w = edge[i].second;

        if (dist[v] == dist[u] + w && c && !vis[v]) {
            int k = dinic(v, std::min(c, limit - flow));

            if (!k) dist[v] = INF;

            edge[i].first -= k;
            edge[i ^ 1].first += k;
            flow += k;
            cost += k * w;
        }
    }

    vis[u] = false;

    return flow;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill(std::begin(head), std::end(head), -1);

    cin >> n >> m;

    s = 0, t = id(n, m, 1) + 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;

            cin >> c;

            if (c == '1') {
                g1[i][j] = true;
                cnt1++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;

            cin >> c;

            if (c == '1') {
                g2[i][j] = true;
                cnt2++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g1[i][j] && !g2[i][j]) {
                add(s, id(i, j), 1, 0);
                add(id(i, j), s, 0, 0);
                cnt++;
            } else if (!g1[i][j] && g2[i][j]) {
                add(id(i, j, 1), t, 1, 0);
                add(t, id(i, j, 1), 0, 0);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;

            cin >> c;

            int x = c - '0';

            add(id(i, j), id(i, j, 1), x >> 1, 0);
            add(id(i, j, 1), id(i, j), 0, 0);

            if (g1[i][j] != g2[i][j] && x % 2 == 1) {
                add(id(i, j), id(i, j, 1), 1, 0);
                add(id(i, j, 1), id(i, j), 0, 0);
            }

            for (auto d : d) {
                int xx = i + d[0],
                    yy = j + d[1];

                if (xx < 1 || xx > n || yy < 1 || yy > m) continue;

                add(id(i, j, 1), id(xx, yy), INF, 1);
                add(id(xx, yy), id(i, j, 1), 0, -1);
            }
        }
    }

    int res = 0;

    while (spfa()) {
        while (int flow = dinic(s, INF)) res += flow;
    }

    if (cnt1 != cnt2 || res < cnt) {
        cout << -1 << endl;
    } else {
        cout << cost << endl;
    }

    return 0;
}
