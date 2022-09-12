#include <iostream>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    std::vector<std::tuple<int, int, int>> data(m);
    std::vector<int> nums;

    for (auto& e : data) {
        int a, b, c;

        cin >> a >> b >> c;

        e = std::make_tuple(a - 1, b - 1, c);
        nums.push_back(c);
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    for (auto& e : data) {
        std::get<2>(e) = std::lower_bound(nums.begin(), nums.end(), std::get<2>(e)) - nums.begin();
    }

    std::vector<std::vector<int>> g(n, std::vector<int>(nums.size(), 0));
    std::vector<std::vector<std::vector<int>>>
        f(n, std::vector<std::vector<int>>(n, std::vector<int>(nums.size(), 0))),
        pos(n, std::vector<std::vector<int>>(n, std::vector<int>(nums.size(), 0))),
        pre(n, std::vector<std::vector<int>>(n, std::vector<int>(nums.size(), 0)));

    for (int len = 1; len <= n; len++) {
        for (int l = 0, r = l + len - 1; r < n; l++, r++) {
            std::for_each(g.begin() + l, g.begin() + r + 1, [&](auto& v) {
                std::fill(v.begin(), v.end(), 0);
            });

            for (const auto& e : data) {
                int a, b, c;
                std::tie(a, b, c) = e;

                if (l <= a && b <= r) {
                    std::for_each(g.begin() + a, g.begin() + b + 1, [&](auto& v) { v[c]++; });
                }
            }

            std::for_each(g.begin() + l, g.begin() + r + 1, [&](auto& v) {
                std::partial_sum(v.rbegin(), v.rend(), v.rbegin());
            });

            for (int i = nums.size() - 1; i >= 0; i--) {
                int max = 0;
                for (int j = l; j <= r; j++) {
                    int t = (j > 0 ? f[l][j - 1][i] : 0)
                          + (j + 1 < n ? f[j + 1][r][i] : 0)
                          + g[j][i] * nums[i];

                    if (max <= t) {
                        max = t;
                        pos[l][r][i] = j;
                    }
                }

                if (i + 1 == nums.size() || f[l][r][i + 1] <= max) {
                    f[l][r][i] = max;
                    pre[l][r][i] = i;
                } else {
                    f[l][r][i] = f[l][r][i + 1];
                    pre[l][r][i] = pre[l][r][i + 1];
                }
            }
        }
    }

    cout << f[0][n - 1][0] << endl;

    std::vector<int> ans(n);

    auto dfs = [&](int l, int r, int k, auto&& dfs) -> void {
        if (l > r) return;

        int p = pos[l][r][k = pre[l][r][k]];

        ans[p] = nums[k];

        dfs(l, p - 1, k, dfs);
        dfs(p + 1, r, k, dfs);
    };

    dfs(0, n - 1, 0, dfs);

    for (const int& x : ans) {
        cout << x << ' ';
    }

    cout << endl;

    return 0;
}
