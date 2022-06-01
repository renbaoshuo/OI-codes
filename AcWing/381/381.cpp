#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

const int N = 55 << 1,
          M = 50005,
          INF = 1e8;

int n, m, s, t, flow, max_flow, ans;

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

            if (!d[v] && w) {
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
    while (scanf("%d%d", &n, &m) != EOF) {
        idx = 0;
        ans = n;
        memset(head, 0xff, sizeof(head));

        for (int i = 0; i < n; i++) {
            add(i, n + i, 1);
            add(n + i, i, 0);
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf(" (%d,%d)", &u, &v);
            add(u + n, v, INF);
            add(v, u + n, 0);
            add(v + n, u, INF);
            add(u, v + n, 0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                s = n + i, t = j;

                for (int k = 0; k < idx; k += 2) {
                    edge[k] += edge[k ^ 1];
                    edge[k ^ 1] = 0;
                }

                max_flow = 0;
                while (bfs()) {
                    while (flow = dinic(s, INF)) max_flow += flow;
                }

                ans = std::min(ans, max_flow);
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
