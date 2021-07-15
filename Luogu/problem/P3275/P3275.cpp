#include <bits/stdc++.h>

using namespace std;

int n, m, x, a, b, head[300005], vis[300005], used[300005], dis[300005], num;
queue<int> q;

struct {
    int next, to, val;
} g[1000005];

void add(int u, int v, int w) {
    g[++num].next = head[u];
    g[num].to = v;
    g[num].val = w;
    head[u] = num;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> a >> b;
        if (x == 1) {
            add(a, b, 0);
            add(b, a, 0);
        } else if (x == 2) {
            add(a, b, 1);
        } else if (x == 3) {
            add(b, a, 0);
        } else if (x == 4) {
            add(b, a, 1);
        } else if (x == 5) {
            add(a, b, 0);
        }
        if (x % 2 == 0 && a == b) {
            cout << -1 << endl;
            exit(0);
        }
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 1;
        dis[i] = 1;
        used[i] = 1;
        q.push(i);
    }
    while (!q.empty()) {
        int z = q.front();
        q.pop();
        if (used[z] >= n - 1) {
            cout << -1 << endl;
            exit(0);
        }
        used[z]++;
        for (int i = head[z]; i; i = g[i].next) {
            int t = g[i].to;
            if (dis[t] < dis[z] + g[i].val) {
                dis[t] = dis[z] + g[i].val;
                if (!vis[t]) {
                    q.push(t);
                    vis[t] = 1;
                }
            }
        }
        vis[z] = 0;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dis[i];
    }
    cout << ans << endl;
    return 0;
}
