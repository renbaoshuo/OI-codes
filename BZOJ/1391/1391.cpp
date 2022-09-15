#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstring>
#include <limits>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e6 + 5;

int n, m, s, t, sum;
int idx, head[N], edge[N << 1], ver[N << 1], next[N << 1];
int dist[N], cur[N];

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

bool bfs() {
    memset(dist, 0x00, sizeof(dist));

    std::queue<int> q;

    dist[s] = 1;
    q.push(s);
    cur[s] = head[s];

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                w = edge[i];

            if (w && !dist[v]) {
                dist[v] = dist[u] + 1;
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

        int v = ver[i],
            w = edge[i];

        if (w && dist[v] == dist[u] + 1) {
            int k = dinic(v, std::min(limit - flow, w));

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

    memset(head, 0xff, sizeof(head));

    cin >> n >> m;

    s = 0, t = n + m + 1;

    for (int i = 1; i <= n; i++) {
        int x, t;

        cin >> x >> t;

        add(s, i, x);
        add(i, s, 0);
        sum += x;

        for (int j = 1; j <= t; j++) {
            int a, b;

            cin >> a >> b;

            add(i, a + n, b);
            add(a + n, i, 0);
        }
    }

    for (int i = 1; i <= m; i++) {
        int y;

        cin >> y;

        add(i + n, t, y);
        add(t, i + n, 0);
    }

    int res = 0, flow;
    while (bfs()) {
        while (flow = dinic(s, std::numeric_limits<int>::max())) res += flow;
    }

    cout << sum - res << endl;

    return 0;
}
