#include <iostream>
#include <algorithm>
#include <array>
#include <limits>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 305;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        std::vector<std::tuple<int, int, int>> data(n);
        std::vector<int> nums;

        for (auto& e : data) {
            int a, b, d;

            cin >> a >> b >> d;

            e = std::make_tuple(a, b, d);
            nums.emplace_back(a);
            nums.emplace_back(b);
        }

        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        for (auto& e : data) {
            std::get<0>(e) = std::lower_bound(nums.begin(), nums.end(), std::get<0>(e)) - nums.begin() + 1;
            std::get<1>(e) = std::lower_bound(nums.begin(), nums.end(), std::get<1>(e)) - nums.begin() + 1;
        }

        int m = nums.size();
        std::array<std::array<int, N << 1>, N << 1> f;

        for (int len = 0; len < m; len++) {
            for (int l = 1, r = 1 + len; r <= m; l++, r++) {
                auto it = data.end();

                for (auto _it = data.begin(); _it != data.end(); _it++) {
                    int a, b, d;
                    std::tie(a, b, d) = *_it;

                    if (l <= a && b <= r && (it == data.end() || d > std::get<2>(*it))) {
                        it = _it;
                    }
                }

                if (it == data.end()) {
                    f[l][r] = 0;
                } else {
                    f[l][r] = std::numeric_limits<int>::max();

                    int a, b, d;
                    std::tie(a, b, d) = *it;

                    for (int i = a; i <= b; i++) {
                        f[l][r] = std::min(f[l][r], f[l][i - 1] + d + f[i + 1][r]);
                    }
                }
            }
        }

        cout << f[1][m] << endl;
    }

    return 0;
}
