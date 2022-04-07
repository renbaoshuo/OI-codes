#include <iostream>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 100005;

int n, ans = std::numeric_limits<int>::max();
std::vector<int> g[N];

int dfs(int u, int fa) {
    int siz = 0, sum = 0;

    for (int v : g[u]) {
        if (v != fa) {
            int s = dfs(v, u);
            siz = std::max(siz, s);
            sum += s;
        }
    }

    ans = std::min(ans, std::max(siz, n - sum - 1));

    return sum + 1;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1);

    cout << ans << endl;

    return 0;
}
