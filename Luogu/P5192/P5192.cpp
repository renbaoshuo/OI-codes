#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5,
          M = 2e6 + 5;
const int INF = 0x3f3f3f3f;

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
    std::fill(std::begin(d), std::end(d), 0);

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

    for (int i = cur[u]; ~i && flow < limit; i = next[i]) {
        cur[u] = i;

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

    while (cin >> n >> m) {
        idx = 0;
        std::fill(std::begin(head), std::end(head), -1);
        std::fill(std::begin(f), std::end(f), 0);

        ss = 0, tt = n + m + 1;

        for (int i = 1, x; i <= m; i++) {
            cin >> x;

            add(ss, i, INF - x);
            add(i, ss, 0);

            f[ss] -= x;
            f[i] += x;
        }

        for (int i = 1, c, d; i <= n; i++) {
            cin >> c >> d;

            add(m + i, tt, d);
            add(tt, m + i, 0);

            for (int j = 1, t, l, r; j <= c; j++) {
                cin >> t >> l >> r;

                t++;

                add(t, m + i, r - l);
                add(m + i, t, 0);

                f[t] -= l;
                f[m + i] += l;
            }
        }

        int sum = 0;
        s = n + m + 2, t = n + m + 3;

        for (int i = 0; i <= n + m + 1; i++) {
            if (f[i] > 0) {
                add(s, i, f[i]);
                add(i, s, 0);
                sum += f[i];
            } else if (f[i] < 0) {
                add(i, t, -f[i]);
                add(t, i, 0);
            }
        }

        add(tt, ss, INF);
        add(ss, tt, 0);

        int res = 0;
        while (bfs()) {
            while (int flow = dinic(s, INF)) res += flow;
        }

        if (res == sum) {
            int x = edge[idx - 1];
            edge[idx - 1] = edge[idx - 2] = 0;

            s = ss, t = tt;

            int res = 0;
            while (bfs()) {
                while (int flow = dinic(s, INF)) res += flow;
            }

            cout << x + res << endl;
        } else {
            cout << -1 << endl;
        }

        cout << endl;
    }

    return 0;
}
