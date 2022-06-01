#include <iostream>
#include <cstring>
#include <limits>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 405,
          M = 15005,
          INF = 0x3f3f3f3f;

int n, m, s, t, flow, cost;

// Graph
int idx, head[N], ver[M << 1], next[M << 1];
std::pair<int, int> edge[M << 1];

//       <  c,   w>

void add(int u, int v, int c, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = std::make_pair(c, w);
    head[u] = idx++;
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
            cost += k * w;
        }
    }
    vis[u] = false;
    return flow;
}

int main() {
    std::ios::sync_with_stdio(false);
    memset(head, 0xff, sizeof(head));
    cin >> n >> m;
    s = 1, t = n;
    for (int i = 1; i <= m; i++) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        add(u, v, c, w);
        add(v, u, 0, -w);
    }

    while (spfa()) {
        flow += dinic(s, INF);
    }
    cout << flow << ' ' << cost << endl;
    return 0;
}
