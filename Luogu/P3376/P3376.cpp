#include <iostream>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205,
          M = 5005;
const int INF = 0x3f3f3f3f;

int n, m, s, t, flow;
long long ans;
int idx, head[N], ver[M << 1], edge[M << 1], next[M << 1];
int d[N], cur[N];

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

bool bfs() {
    std::fill_n(d, N, 0);

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

        if (w && d[v] == d[u] + 1) {
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
    cin.tie(nullptr);

    std::fill_n(head, N, -1);

    cin >> n >> m >> s >> t;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        add(u, v, w);
        add(v, u, 0);
    }

    while (bfs()) {
        while (flow = dinic(s, INF)) ans += flow;
    }

    cout << ans << endl;

    return 0;
}
