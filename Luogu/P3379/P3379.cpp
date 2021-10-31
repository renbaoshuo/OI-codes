#include <bits/stdc++.h>

using namespace std;

int n, m, s, root, a, b, dep[500005], fa[500005][20];
vector<int> tr[500005];

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
                for (int k = 1; k <= 19; k++) {
                    fa[i][k] = fa[fa[i][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int k = 19; k >= 0; k--) {
        if (dep[fa[a][k]] >= dep[b]) {
            a = fa[a][k];
        }
    }
    if (a == b) return a;
    for (int k = 19; k >= 0; k--) {
        if (fa[a][k] != fa[b][k]) {
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int main() {
    cin >> n >> m >> root;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    bfs(root);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}
