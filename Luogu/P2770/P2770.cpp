#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105,
          M = 5005,
          INF = 0x3f3f3f3f;

int n, m, s, t, flow, cost;
bool flag;
std::map<std::string, int> map;
std::string a[N];

// Graph
int idx, head[N], ver[M << 1], next[M << 1];
std::pair<int, int> edge[M << 1];

void add(int u, int v, int flow, int cost) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = std::make_pair(flow, cost);
    head[u] = idx++;
}

// Dinic
int dist[N];
bool vis[N];

bool spfa() {
    memset(vis, 0x00, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));

    std::queue<int> q;
    q.push(s);
    dist[s] = 0;
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;

        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                c = edge[i].first,
                w = edge[i].second;

            if (dist[v] > dist[u] + w && c > 0) {
                dist[v] = dist[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    return dist[t] != INF;
}

int dinic(int u, int limit) {
    if (u == t) return limit;

    int flow = 0;
    vis[u] = true;
    for (int i = head[u]; ~i && flow < limit; i = next[i]) {
        int v = ver[i],
            c = edge[i].first,
            w = edge[i].second;

        if (dist[v] == dist[u] + w && c && !vis[v]) {
            int k = dinic(v, std::min(c, limit - flow));
            if (!k) dist[v] = INF;
            edge[i].first -= k;
            edge[i ^ 1].first += k;
            flow += k;
            cost += k * w;
        }
    }
    vis[u] = false;

    return flow;
}

void dfs1(int u) {
    vis[u] = true;
    cout << a[u - n] << endl;
    for (int i = head[u]; ~i; i = next[i]) {
        if (ver[i] <= n && !edge[i].first) {
            dfs1(ver[i] + n);
            return;
        }
    }
}

void dfs2(int u) {
    for (int i = head[u]; ~i; i = next[i]) {
        if (ver[i] <= n && !edge[i].first && !vis[ver[i] + n]) {
            dfs2(ver[i] + n);
        }
    }
    cout << a[u - n] << endl;
}

int main() {
    std::ios::sync_with_stdio(false);

    memset(head, 0xff, sizeof(head));

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        map[a[i]] = i;
        if (i == 1 || i == n) {
            add(i, i + n, 2, 0);
            add(i + n, i, 0, 0);
        } else {
            add(i, i + n, 1, 0);
            add(i + n, i, 0, 0);
        }
    }

    s = 1, t = n * 2;
    for (int i = 1; i <= m; i++) {
        std::string u, v;
        cin >> u >> v;
        int uu = map[u],
            vv = map[v];
        if (uu == 1 && vv == n) flag = true;
        add(uu + n, vv, 1, -1);
        add(vv, uu + n, 0, 1);
    }

    while (spfa()) flow += dinic(s, INF);

    if (flow == 2) {
        cout << -cost << endl;
        dfs1(n + 1);
        dfs2(n + 1);
    } else if (!flag) {  // flow != 2
        cout << "No Solution!" << endl;
    } else {  // flow != 2 && flag
        cout << 2 << endl
             << a[1] << endl
             << a[n] << endl
             << a[1] << endl;
    }

    return 0;
}
