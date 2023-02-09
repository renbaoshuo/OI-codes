#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int mod = 1e8 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n, m, q;
        std::vector<int> c{{0}}, v{{0}}, t{{0}};

        cin >> n >> m >> q;

        std::copy_n(std::istream_iterator<int>(cin), n, std::back_inserter(c));
        std::copy_n(std::istream_iterator<int>(cin), n, std::back_inserter(v));
        std::copy_n(std::istream_iterator<int>(cin), n, std::back_inserter(t));

        std::vector<std::vector<std::pair<int, int>>> vec(n + 1);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= t[i]; j <<= 1) {
                vec[i].emplace_back(c[i] * j, v[i] * j);

                t[i] -= j;
            }

            if (t[i]) {
                vec[i].emplace_back(c[i] * t[i], v[i] * t[i]);
            }
        }

        std::vector<std::vector<int>>
            f(n + 2, std::vector<int>(m + 2, 0)),
            g(n + 2, std::vector<int>(m + 2, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 0; j--) {
                f[i][j] = std::max(f[i][j], f[i - 1][j]);
            }

            for (auto o : vec[i]) {
                for (int j = m; j >= o.first; j--) {
                    f[i][j] = std::max(f[i][j], f[i][j - o.first] + o.second);
                }
            }
        }

        for (int i = n; i; i--) {
            for (int j = m; j >= 0; j--) {
                g[i][j] = std::max(g[i][j], g[i + 1][j]);
            }

            for (auto o : vec[i]) {
                for (int j = m; j >= o.first; j--) {
                    g[i][j] = std::max(g[i][j], g[i][j - o.first] + o.second);
                }
            }
        }

        int lst = 0;

        while (q--) {
            int x, y;

            cin >> x >> y;

            int l = std::min((x + lst - 1) % n + 1, (y + lst - 1) % n + 1),
                r = std::max((x + lst - 1) % n + 1, (y + lst - 1) % n + 1);

            int ans = 0, sum = 0;
            std::vector<int> h(m + 1);

            for (int i = 0; i <= m; i++) {
                for (int j = 0; i + j <= m; j++) {
                    h[i + j] = std::max(h[i + j], f[l - 1][i] + g[r + 1][j]);
                }
            }

            for (int i = 1; i <= m; i++) {
                ans = (ans + h[i]) % mod;
                sum ^= h[i];
            }

            cout << (lst = ans) << ' ' << sum << endl;
        }
    }

    return 0;
}
