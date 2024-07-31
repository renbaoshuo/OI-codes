#include <iostream>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5;

int n;
int siz[N],     // siz: 子树大小（所有子树上节点数 + 该节点）
    weight[N];  // weight: 所有子树大小最大值
int centroid;   // centroid: 重心
int dep[N];
std::vector<int> g[N];

void dfs1(int u, int f) {
    siz[u] = 1;
    weight[u] = 0;

    for (int v : g[u]) {
        if (v == f) continue;

        dfs1(v, u);

        siz[u] += siz[v];
        weight[u] = std::max(weight[u], siz[v]);
    }

    // 顶上也算一棵子树
    weight[u] = std::max(weight[u], n - siz[u]);

    // 记录重心
    if (centroid == 0) centroid = u;
    else if (weight[u] < weight[centroid]) centroid = u;
    // 重心相同，取编号小的
    else if (weight[u] == weight[centroid] && u < centroid) centroid = u;
}

void dfs2(int u, int f) {
    dep[u] = dep[f] + 1;

    for (int v : g[u]) {
        if (v == f) continue;

        dfs2(v, u);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs1(1, 0);
    dfs2(centroid, 0);

    cout << centroid << ' ' << std::accumulate(dep + 1, dep + 1 + n, 0) - n << endl;

    return 0;
}
