#include <iostream>
#include <cstring>
#include <limits>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205,
          M = 10205;

int n, m, s, t;
int idx, head[N], ver[M << 2], next[M << 2];
std::pair<int, int> edge[M << 2];
int f[N], d[N], cur[N];

void add(int u, int v, int a, int b) {
    ver[idx] = v;
    edge[idx] = std::make_pair(a, b);
    next[idx] = head[u];
    head[u] = idx++;
}

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
            int v = ver[i];

            if (!d[v] && edge[i].first) {
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
        int v = ver[i];

        if (d[v] == d[u] + 1 && edge[i].first) {
            int k = dinic(v, std::min(edge[i].first, limit - flow));
            if (!k) d[v] = 0;
            edge[i].first -= k;
            edge[i ^ 1].first += k;
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

    for (int i = 1, u, v, a, b; i <= m; i++) {
        cin >> u >> v >> a >> b;

        add(u, v, b - a, a);
        add(v, u, 0, 0);

        f[u] -= a, f[v] += a;
    }

    int sum = 0;
    s = 0, t = n + 1;

    for (int i = 1; i <= n; i++) {
        if (f[i] > 0) {
            add(s, i, f[i], 0);
            add(i, s, 0, 0);
            sum += f[i];
        } else if (f[i] < 0) {
            add(i, t, -f[i], 0);
            add(t, i, 0, 0);
        }
    }

    int res = 0, flow;
    while (bfs()) {
        while (flow = dinic(s, std::numeric_limits<int>::max())) res += flow;
    }

    if (res == sum) {
        cout << "YES" << endl;

        for (int i = 0; i < m << 1; i += 2) {
            cout << edge[i ^ 1].first + edge[i].second << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
