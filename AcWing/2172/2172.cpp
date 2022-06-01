#include <iostream>
#include <cstring>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

int n, m, s, t, flow, ans;

const int N = 10005,
          M = 100005;

// Graph
int idx, head[N], edge[M << 1], ver[M << 1], next[M << 1];

void add(int u, int v, int w) {
    next[idx] = head[u];
    edge[idx] = w;
    ver[idx] = v;
    head[u] = idx++;
}

// Dinic
int d[N], cur[N];

bool bfs() {
    memset(d, 0x00, sizeof(d));
    std::queue<int> q;
    q.push(s);
    d[s] = 1;
    cur[s] = head[s];
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                w = edge[i];
            if (w && !d[v]) {
                d[v] = d[u] + 1;
                cur[v] = head[v];
                if (v == t) return true;
                q.push(v);
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

        int v = ver[i];
        if (d[v] == d[u] + 1 && edge[i]) {
            int k = dinic(v, std::min(edge[i], limit - flow));
            if (!k) d[v] = 0;
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
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }

    while (bfs()) {
        while (flow = dinic(s, 0x3f3f3f3f)) ans += flow;
    }

    cout << ans << endl;
    return 0;
}
