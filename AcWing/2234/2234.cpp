#include <cstring>
#include <iostream>
#include <limits>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 100005,
          M = 1000005;

int n, m, sc, tc, s, t, flow, ans;

// Graph
int idx, head[N], edge[M << 1], ver[M << 1], next[M << 1];

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

// Dinic
int d[N], cur[N];

bool bfs() {
    std::memset(d, 0x00, sizeof(d));
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
    for (int &i = cur[u]; ~i && flow < limit; i = next[i]) {
        int v = ver[i],
            w = edge[i];
        if (d[v] == d[u] + 1 && w) {
            int k = dinic(v, std::min(w, limit - flow));
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
    cin >> n >> m >> sc >> tc;
    s = 0, t = n + 1;

    for (int i = 1; i <= sc; i++) {
        int x;
        cin >> x;
        add(s, x, std::numeric_limits<int>::max());
        add(x, s, 0);
    }
    for (int i = 1; i <= tc; i++) {
        int x;
        cin >> x;
        add(x, t, std::numeric_limits<int>::max());
        add(t, x, 0);
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }

    while (bfs()) {
        while (flow = dinic(s, std::numeric_limits<int>::max())) ans += flow;
    }
    cout << ans << endl;
    return 0;
}
