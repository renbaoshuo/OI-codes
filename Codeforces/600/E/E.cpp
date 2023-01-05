#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, color[N], cnt[N], siz[N], son[N], max;
long long ans[N], sum;
std::vector<int> g[N];

void dfs(int u, int f) {
    siz[u] = 1;

    for (int v : g[u]) {
        if (v == f) continue;

        dfs(v, u);

        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}

void add(int u) {
    cnt[color[u]]++;

    if (cnt[color[u]] > max) {
        max = cnt[color[u]];
        sum = color[u];
    } else if (cnt[color[u]] == max) {
        sum += color[u];
    }
}

void del(int u) {
    cnt[color[u]]--;
}

void add(int u, int f) {
    add(u);

    for (int v : g[u]) {
        if (v != f) add(v, u);
    }
}

void del(int u, int f) {
    del(u);

    for (int v : g[u]) {
        if (v != f) del(v, u);
    }
}

void dsu(int u, int f) {
    for (int v : g[u]) {
        if (v == f || v == son[u]) continue;

        dsu(v, u);
        del(v, u);
        max = sum = 0;
    }

    if (son[u]) dsu(son[u], u);

    for (auto v : g[u]) {
        if (v == f || v == son[u]) continue;

        add(v, u);
    }

    add(u);
    ans[u] = sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;

        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    dfs(1, 0);
    dsu(1, 0);

    std::copy_n(ans + 1, n, std::ostream_iterator<long long>(cout, " "));

    cout << endl;

    return 0;
}
