#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
#include <unordered_map>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55,
          M = N * N * 4;
const int INF = 0x3f3f3f3f;

const std::unordered_map<char, std::pair<int, int>> d{
    {'L', {0, -1}},
    {'R', {0, 1}},
    {'U', {-1, 0}},
    {'D', {1, 0}},
};

int n, m, k, s, t, cnt, id[N][N], cost;
int idx, head[M], ver[M << 1], next[M << 1];
std::pair<int, int> edge[M << 1];
int dist[M];
bool vis[M];

void add(int u, int v, int c, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = {c, w};
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
                    q.emplace(v);

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

        if (dist[v] == dist[u] + w && c > 0 && !vis[v]) {
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

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            id[i][j] = ++cnt;

            add(s, id[i][j], 1, 0);
            add(id[i][j], s, 0, 0);
        }
    }

    for (int i = 1; i <= k; i++) {
        int x, y;
        char d;

        cin >> x >> y >> d;

        x++, y++;

        int xx = x + ::d.at(d).first,
            yy = y + ::d.at(d).second,
            p = ++cnt;

        add(id[xx][yy], p, 1, 0);
        add(p, id[xx][yy], 0, 0);

        id[xx][yy] = ++cnt;

        add(p, id[xx][yy], 1, 0);
        add(id[xx][yy], p, 0, 0);

        add(id[x][y], p, 1, -1);
        add(p, id[x][y], 0, 1);
    }

    t = ++cnt;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            add(id[i][j], t, 1, 0);
            add(t, id[i][j], 0, 0);
        }
    }

    while (spfa() && dist[t] < 0) {
        while (dinic(s, INF)) {}
    }

    cout << k + cost << endl;

    return 0;
}
