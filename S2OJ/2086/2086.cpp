#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505,
          M = 5e4 + 5;
const int INF = 0x3f3f3f3f;

int n, m, e, s, t;
int idx, head[N << 1], ver[M << 2], edge[M << 2], next[M << 2];
int d[N << 1], cur[N << 1];

void add(int u, int v, int w) {
    ver[idx] = v;
    edge[idx] = w;
    next[idx] = head[u];
    head[u] = idx++;
}

bool bfs() {
    std::fill(std::begin(d), std::end(d), 0);

    std::queue<int> q;

    q.emplace(s);
    d[s] = 1;
    cur[s] = head[s];

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                w = edge[i];

            if (!d[v] && w) {
                d[v] = d[u] + 1;
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

        if (d[v] == d[u] + 1 && w) {
            int k = dinic(v, std::min(limit - flow, w));

            if (!k) d[v] = 0;

            flow += k;
            edge[i] -= k;
            edge[i ^ 1] += k;
        }
    }

    return flow;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill(std::begin(head), std::end(head), -1);

    cin >> n >> m >> e;

    s = 0, t = n + m + 1;

    for (int i = 1; i <= n; i++) {
        add(s, i, 1);
        add(i, s, 0);
    }

    for (int i = 1; i <= m; i++) {
        add(n + i, t, 1);
        add(t, n + i, 0);
    }

    for (int i = 1, u, v; i <= e; i++) {
        cin >> u >> v;

        add(u, v + n, 1);
        add(v + n, u, 0);
    }

    int res = 0;

    while (bfs()) {
        while (int flow = dinic(s, INF)) res += flow;
    }

    cout << res << endl;

    return 0;
}
