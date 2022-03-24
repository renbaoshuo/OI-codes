#include <cstring>
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105,
          M = 2005,
          INF = 0x3f3f3f3f;

int n, s, t, a[N], sum, avg, cost;

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

// Dinic
int dist[N];
bool vis[N];

bool spfa() {
    std::memset(vis, 0x00, sizeof(vis));
    std::memset(dist, 0x3f, sizeof(dist));

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

            if (dist[v] > dist[u] + w && c > 0) {
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

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    avg = sum / n;

    s = 0, t = n + 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] - avg > 0) {
            add(s, i, a[i] - avg, 0);
            add(i, s, 0, 0);
        } else if (a[i] - avg < 0) {
            add(i, t, avg - a[i], 0);
            add(t, i, 0, 0);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            add(i, i - 1, INF, 1);
            add(i - 1, i, 0, -1);
        }
        if (i < n) {
            add(i, i + 1, INF, 1);
            add(i + 1, i, 0, -1);
        }
    }

    add(1, n, INF, 1);
    add(n, 1, 0, -1);
    add(n, 1, INF, 1);
    add(1, n, 0, -1);

    while (spfa()) dinic(s, INF);

    cout << cost << endl;

    return 0;
}
