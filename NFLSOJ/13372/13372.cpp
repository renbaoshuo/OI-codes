#include <iostream>
#include <fstream>
#include <vector>

// using std::cin;
// using std::cout;
std::ifstream cin("rain.in");
std::ofstream cout("rain.out");
const char endl = '\n';

const int N = 2505;

int n, m, k, a[N], b[N], tag[N], match[N], ans;
std::vector<int> g[N];

bool dfs(int u, int t) {
    if (tag[u] == t) return false;

    tag[u] = t;

    for (int v : g[u]) {
        if (!match[v]) {
            ans -= a[u];
            match[v] = u;
            return true;
        } else if (dfs(match[v], t)) {
            ans += a[match[v]];
            ans -= a[u];
            match[v] = u;
            return true;
        }
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        ans += a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];

        ans += b[i];
    }

    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;

        if (a[x] == b[y]) {
            g[x].emplace_back(y);
        }
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, i);
    }

    cout << ans << endl;

    return 0;
}
