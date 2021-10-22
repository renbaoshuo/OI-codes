#include <bits/stdc++.h>

using namespace std;

int n, m, root, a, b, p, dep[40005], fa[40005][16];
vector<int> tr[40005];

void bfs(int root) {
    memset(dep, 0x3f, sizeof(dep));
    dep[0] = 0;
    dep[root] = 1;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i : tr[t]) {
            if (dep[i] > dep[t] + 1) {
                dep[i] = dep[t] + 1;
                q.push(i);
                fa[i][0] = t;
                for (int k = 1; k <= 15; k++) {
                    fa[i][k] = fa[fa[i][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int k = 15; k >= 0; k--) {
        if (dep[fa[a][k]] >= dep[b]) {
            a = fa[a][k];
        }
    }
    if (a == b) return a;
    for (int k = 15; k >= 0; k--) {
        if (fa[a][k] != fa[b][k]) {
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (b == -1) {
            root = a;
        } else {
            tr[a].push_back(b);
            tr[b].push_back(a);
        }
    }
    bfs(root);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        p = lca(a, b);
        if (p == a) {
            cout << 1 << endl;
        } else if (p == b) {
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
