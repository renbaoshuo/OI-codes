#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = 2e5 + 5;

int t, n, m, cnt, ans[M];
int idx, head[N], edge[M << 1], next[M << 1];
int din[N], dout[N];
bool vis[M << 1];

void add(int u, int v) {
    next[idx] = head[u];
    edge[idx] = v;
    head[u] = idx++;
}

void dfs(int u) {
    for (int &i = head[u]; ~i;) {
        if (vis[i]) {
            i = next[i];
            continue;
        }

        int v = edge[i];

        vis[i] = true;
        if (t == 1) vis[i ^ 1] = true;

        int x;
        if (t == 1) x = i & 1 ? -(i >> 1) - 1 : (i >> 1) + 1;
        else x = i + 1;

        i = next[i];

        dfs(v);

        ans[++cnt] = x;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> n >> m;

    memset(head, 0xff, sizeof(head));

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        add(u, v);
        if (t == 1) add(v, u);

        din[u]++, dout[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (t == 1 && (din[i] + dout[i] & 1) || t == 2 && (din[i] != dout[i])) {
            cout << "NO" << endl;

            exit(0);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (~head[i]) {
            dfs(i);

            break;
        }
    }

    if (cnt < m) {
        cout << "NO" << endl;

        exit(0);
    }

    cout << "YES" << endl;

    for (int i = cnt; i; i--) {
        cout << ans[i] << ' ';
    }

    cout << endl;

    return 0;
}
