#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

void solve() {
    int n, m, q;

    cin >> n >> m >> q;

    std::vector<std::pair<int, int> > g(n + 1), h(m + 1);

    for (int i = 1, op, x, c; i <= q; i++) {
        cin >> op >> x >> c;

        if (op == 0) {
            g[x] = std::make_pair(c, i);
        } else {  // op == 1
            h[x] = std::make_pair(c, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i].second > h[j].second) {
                cout << g[i].first;
            } else {
                cout << h[j].first;
            }

            if (j < m) {
                cout << ' ';
            } else {  // j == m
                cout << endl;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--) solve();

    return 0;
}
