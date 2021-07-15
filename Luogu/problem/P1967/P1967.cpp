#include <bits/stdc++.h>

using namespace std;

int n, m, q, x, y, c, px, py, ans[50005], fa[10005];
set<int> f[10005];
set<int>::iterator it;

struct edge {
    int u, v, cost;

    bool operator<(edge b) {
        return cost > b.cost;
    }
} es[50005];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    memset(ans, 0xff, sizeof(ans));
    for (int i = 1; i < 10005; i++) {
        fa[i] = i;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> es[i].u >> es[i].v >> es[i].cost;
    }
    sort(es, es + m);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        f[x].insert(i);
        f[y].insert(i);
    }
    for (int i = 0; i < m; i++) {
        x = es[i].u;
        y = es[i].v;
        c = es[i].cost;
        px = find(x);
        py = find(y);
        if (px == py) {
            continue;
        } else {
            if (f[px].size() > f[py].size()) {
                swap(px, py);
            }
            vector<int> tmp;
            for (it = f[px].begin(); it != f[px].end(); it++) {
                if (f[py].count(*it)) {
                    ans[*it] = c;
                    tmp.push_back(*it);
                }
                f[py].insert(*it);
            }
            for (int i = 0; i < tmp.size(); i++) {
                f[py].erase(tmp[i]);
            }
            fa[px] = py;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
