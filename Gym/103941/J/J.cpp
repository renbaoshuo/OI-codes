#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, a[N], mex[N], ans[N];
int cnt, id[N], rid[N], lid[N], min[N], siz[N], son[N];
bool vis[N];
std::vector<int> g[N];

void dfs1(int u) {
    rid[id[u] = ++cnt] = u;
    siz[u] = 1;
    min[u] = a[u];

    for (int v : g[u]) {
        dfs1(v);

        siz[u] += siz[v];
        min[u] = std::min(min[u], min[v]);

        if (siz[v] > siz[son[u]]) son[u] = v;
    }

    lid[u] = cnt;
}

void dfs2(int u, bool clean = true) {
    for (int v : g[u]) {
        if (v != son[u]) dfs2(v);
    }

    if (son[u]) dfs2(son[u], false);

    for (int v : g[u]) {
        if (v == son[u]) continue;

        for (int i = id[v]; i <= lid[v]; i++) {
            vis[a[rid[i]]] = true;
        }
    }

    vis[a[u]] = true;
    while (vis[cnt]) cnt++;
    mex[u] = cnt;

    if (clean) {
        for (int i = id[u]; i <= lid[u]; i++) {
            vis[a[rid[i]]] = false;
        }
        cnt = 0;
    }
}

void dfs3(int u) {
    ans[mex[u]] = std::max(ans[mex[u]], siz[u]);
    ans[min[u]] = std::max(ans[min[u]], n - siz[u]);

    for (int v : g[u]) dfs3(v);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2, x; i <= n; i++) {
        cin >> x;

        g[x].emplace_back(i);
    }

    dfs1(1);
    cnt = 0;
    dfs2(1);
    dfs3(1);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }

    cout << n << endl;

    return 0;
}
