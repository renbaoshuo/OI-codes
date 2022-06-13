#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 100005;

int n, m, q, d_a[N], d_b[N];
bool a[N], b[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    if (a[1] != a[n]) d_a[0] = 1;
    for (int i = 1; i <= n; i++) {
        d_a[i] = d_a[i - 1] + (a[i] != a[i + 1]);
    }

    if (b[1] != b[m]) d_b[0] = 1;
    for (int i = 1; i <= m; i++) {
        d_b[i] = d_b[i - 1] + (b[i] != b[i + 1]);
    }

    cin >> q;

    while (q--) {
        std::pair<int, int> s, e;

        cin >> s.first >> s.second >> e.first >> e.second;

        cout << std::min({
                    std::abs(d_a[s.first - 1] - d_a[e.first - 1]),
                    d_a[n - 1] - d_a[std::max(s.first, e.first) - 1] + d_a[std::min(s.first, e.first) - 1],
                }) +
                    std::min({
                        std::abs(d_b[s.second - 1] - d_b[e.second - 1]),
                        d_b[m - 1] - d_b[std::max(s.second, e.second) - 1] + d_b[std::min(s.second, e.second) - 1],
                    })
             << endl;
    }

    return 0;
}
