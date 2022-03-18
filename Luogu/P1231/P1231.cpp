#include <cstring>
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 100005,
          M = 1000005;

int n, f, d, m, flow, ans;

// Graph
int idx, head[N], edge[M << 1], ver[M << 1], next[M << 1];

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

// Dinic
int dist[N], cur[N];

bool bfs() {
    memset(dist, 0x00, sizeof(dist));
    std::queue<int> q;
    q.push(0);
    dist[0] = 1;
    cur[0] = head[0];

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                w = edge[i];
            if (w && !dist[v]) {
                dist[v] = dist[u] + 1;
                cur[v] = head[v];
                if (v == n) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int dinic(int u, int limit) {
    if (u == n) return limit;

    int flow = 0;
    for (int &i = cur[u]; ~i && flow < limit; i = next[i]) {
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
    memset(head, 0xff, sizeof(head));
    cin >> n >> f >> d;
    for (int i = 1; i <= f; i++) {
        add(0, i, 1);
        add(i, 0, 0);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(y, f + d + x, 1);
        add(f + d + x, y, 0);
    }

    for (int i = 1; i <= n; i++) {
        add(f + d + i, f + d + n + i, 1);
        add(f + d + n + i, f + d + i, 0);
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(f + d + n + x, f + y, 1);
        add(f + y, f + d + n + x, 0);
    }

    n = f + d + n * 2 + 1;
    for (int i = 1; i <= d; i++) {
        add(f + i, n, 1);
        add(n, f + i, 0);
    }

    while (bfs()) {
        while (flow = dinic(0, 0x3f3f3f3f)) ans += flow;
    }
    cout << ans << endl;
    return 0;
}
