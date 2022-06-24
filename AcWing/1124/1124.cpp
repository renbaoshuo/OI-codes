#include <iostream>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505;

int m, g[N][N], d[N];
int min = std::numeric_limits<int>::max(),
    max = std::numeric_limits<int>::min();
int cnt, ans[N << 1];

void dfs(int u) {
    for (int i = min; i <= max; i++) {
        if (g[u][i]) {
            g[u][i]--, g[i][u]--;

            dfs(i);
        }
    }

    ans[++cnt] = u;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m;

    while (m--) {
        int u, v;

        cin >> u >> v;

        g[u][v]++, g[v][u]++;
        d[u]++, d[v]++;

        min = std::min({min, u, v});
        max = std::max({max, u, v});
    }

    int s = min;
    for (int i = min; i <= max; i++) {
        if (d[i] & 1) {
            s = i;
            break;
        }
    }

    dfs(s);

    for (int i = cnt; i; i--) {
        cout << ans[i] << endl;
    }

    return 0;
}
