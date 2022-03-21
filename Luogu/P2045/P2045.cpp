#include <cstring>
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5005,
          M = 100005,
          INF = 0x3f3f3f3f;

int n, k, s, t, ans;

// Graph
int idx, head[N], ver[M << 1], next[M << 1];
std::pair<int, int> edge[M << 1];
//      <flow, cost>

void add(int u, int v, int flow, int cost) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = std::make_pair(flow, cost);
    head[u] = idx++;
}

inline int id(int i, int j, int k = 0) {
    return (i - 1) * n + j + k * n * n;
}

// Dinic
int dist[N];
bool vis[N];

bool spfa() {
    memset(vis, 0x00, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));

    std::queue<int> q;
    q.push(s);
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
            ans += k * w;
        }
    }
    vis[u] = false;

    return flow;
}

int main() {
    std::ios::sync_with_stdio(false);

    memset(head, 0xff, sizeof(head));

    cin >> n >> k;

    s = 0;
    add(s, id(1, 1), k, 0);
    add(id(1, 1), s, 0, 0);

    t = id(n, n, 1) + 1;
    add(id(n, n, 1), t, k, 0);
    add(t, id(n, n, 1), 0, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;

            add(id(i, j), id(i, j, 1), 1, -w);
            add(id(i, j, 1), id(i, j), 0, w);

            add(id(i, j), id(i, j, 1), INF, 0);
            add(id(i, j, 1), id(i, j), 0, 0);

            if (i < n) {
                add(id(i, j, 1), id(i + 1, j), INF, 0);
                add(id(i + 1, j), id(i, j, 1), 0, 0);
            }

            if (j < n) {
                add(id(i, j, 1), id(i, j + 1), INF, 0);
                add(id(i, j + 1), id(i, j, 1), 0, 0);
            }
        }
    }

    while (spfa()) dinic(s, INF);

    cout << -ans << endl;
    return 0;
}
