#include <cstring>
#include <iostream>
#include <limits>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005,
          M = 100005;
const int to[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int m, n, u, s, t, flow, ans, sum;

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
    d[s] = 1;
    q.push(s);
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
        if (w && d[v] == d[u] + 1) {
            int k = dinic(v, std::min(limit - flow, w));
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

    cin >> n >> m;
    s = 0, t = n * m + 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int w, u = (i - 1) * m + j;
            cin >> w;
            sum += w;

            if ((i + j) & 1) {
                add(s, u, w);
                add(u, s, 0);

                for (int k = 0; k < 4; k++) {
                    int xx = i + to[k][0],
                        yy = j + to[k][1];
                    if (1 <= xx && xx <= n && 1 <= yy && yy <= m) {
                        int v = (xx - 1) * m + yy;
                        add(u, v, std::numeric_limits<int>::max());
                        add(v, u, 0);
                    }
                }
            } else {
                add(u, t, w);
                add(t, u, 0);
            }
        }
    }

    while (bfs()) {
        while (flow = dinic(s, std::numeric_limits<int>::max())) ans += flow;
    }

    cout << sum - ans << endl;
    return 0;
}
