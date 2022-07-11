#include <iostream>
#include <cstring>
#include <limits>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205,
          M = 10205;

int n, m, s, t, ss, tt;
int idx, head[N], ver[M << 2], edge[M << 2], next[M << 2];
int f[N], d[N], cur[N];

void add(int u, int v, int w) {
    ver[idx] = v;
    edge[idx] = w;
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
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, 0xff, sizeof(head));

    cin >> n >> m >> ss >> tt;

    for (int i = 1, u, v, a, b; i <= m; i++) {
        cin >> u >> v >> a >> b;

        add(u, v, b - a);
        add(v, u, 0);

        f[u] -= a, f[v] += a;
    }

    int sum = 0;
    s = 0, t = n + 1;

    for (int i = 1; i <= n; i++) {
        if (f[i] > 0) {
            add(s, i, f[i]);
            add(i, s, 0);
            sum += f[i];
        } else if (f[i] < 0) {
            add(i, t, -f[i]);
            add(t, i, 0);
        }
    }

    add(tt, ss, std::numeric_limits<int>::max());
    add(ss, tt, 0);

    int res = 0, flow;
    while (bfs()) {
        while (flow = dinic(s, std::numeric_limits<int>::max())) res += flow;
    }

    if (res == sum) {
        int x = edge[idx - 1];
        edge[idx - 1] = edge[idx - 2] = 0;

        s = ss, t = tt;

        int res = 0, flow;
        while (bfs()) {
            while (flow = dinic(s, std::numeric_limits<int>::max())) res += flow;
        }

        cout << x + res << endl;
    } else {
        cout << "please go home to sleep" << endl;
    }

    return 0;
}
