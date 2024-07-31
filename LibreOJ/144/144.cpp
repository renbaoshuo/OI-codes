#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, m, r, v[N];
long long f[N];
int cnt, in[N], out[N];
std::vector<int> g[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (int i = x; i <= n; i += lowbit(i)) {
        f[i] += y;
    }
}

long long query(int x) {
    long long res = 0;

    for (int i = x; i; i -= lowbit(i)) {
        res += f[i];
    }

    return res;
}

void dfs(int u, int f) {
    in[u] = ++cnt;
    add(cnt, v[u]);

    for (int v : g[u]) {
        if (v == f) continue;

        dfs(v, u);
    }

    out[u] = cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(r, 0);

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int a, x;

            cin >> a >> x;

            add(in[a], x);
        } else {  // op == 2
            int a;

            cin >> a;

            cout << query(out[a]) - query(in[a] - 1) << endl;
        }
    }

    return 0;
}
