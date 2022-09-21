#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int INF = 0x3f3f3f3f;

class DSU {
  private:
    std::vector<int> fa;

  public:
    DSU(int _n = 0)
        : fa(_n) {
        std::iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);

        fa[x] = y;

        return x != y;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n, m;

        cin >> n >> m;

        std::vector<int> a(n), b(n);
        std::vector<std::tuple<int, int, int>> edges;
        std::vector<bool> f(1 << n, false);

        for (int i = 0, u, v, w; i < m; i++) {
            cin >> u >> v >> w;

            edges.emplace_back(u - 1, v - 1, w);
        }

        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        auto check = [&](int s) -> bool {
            auto in_block = [&](int x) -> bool {
                return s >> x & 1;
            };

            int sum = 0, root = 0;
            DSU dsu(n);
            std::vector<std::tuple<int, int, int>> block_edges;

            for (auto& edge : edges) {
                int u, v;

                std::tie(u, v, std::ignore) = edge;

                if (in_block(u) && in_block(v)) {
                    block_edges.emplace_back(edge);
                }
            }

            std::sort(block_edges.begin(), block_edges.end(), [](auto& lhs, auto& rhs) {
                return std::get<2>(lhs) < std::get<2>(rhs);
            });

            for (int i = 0; i < n; i++) {
                if (in_block(i)) sum += a[i] - b[i];
            }

            for (auto& edge : block_edges) {
                int u, v, w;

                std::tie(u, v, w) = edge;

                if (dsu.merge(u, v)) sum -= w;
            }

            for (int i = 0; i < n; i++) {
                if (in_block(i) && dsu.find(i) == i) {
                    root = i;
                }
            }

            for (int i = 0; i < n; i++) {
                if (in_block(i) && dsu.find(i) != root) {
                    return false;
                }
            }

            return sum >= 0;
        };

        f[0] = true;
        for (int s = 1; s < 1 << n; s++) {
            f[s] = check(s);

            for (int i = s; i; i = (i - 1) & s) {
                f[s] = f[s] || f[i] && f[s ^ i];
            }
        }

        cout << (f[(1 << n) - 1] ? "Yes" : "No") << endl;
    }

    return 0;
}
