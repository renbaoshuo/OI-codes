#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, m, k, c, d[N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k >> c;

    for (int i = 1, u, v; i <= k; i++) {
        cin >> u >> v;

        d[u]++, d[v + n]++;
    }

    for (int i = 1; i <= n + m; i++) {
        if (d[i] % c != 0) ans++;
    }

    cout << ans << endl;

    return 0;
}
