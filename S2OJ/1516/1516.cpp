#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2505;

int n, k, l[N], r[N], w[N];
long long sum, f[N << 1];
std::vector<int> nums;
std::vector<std::pair<int, int>> g[N << 1];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> w[i];

        nums.emplace_back(l[i]);
        nums.emplace_back(r[i]);
        sum += w[i];
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    for (int i = 1; i <= n; i++) {
        l[i] = std::lower_bound(nums.begin(), nums.end(), l[i]) - nums.begin() + 1;
        r[i] = std::lower_bound(nums.begin(), nums.end(), r[i]) - nums.begin() + 1;

        g[l[i]].emplace_back(r[i], w[i]);
    }

    for (int i = 1; i <= nums.size(); i++) {
        std::priority_queue<int, std::vector<int>, std::greater<>> q;
        long long res = 0;

        for (int j = i; j; j--) {
            for (auto e : g[j]) {
                if (e.first <= i) {
                    if (q.size() < k) {
                        q.emplace(e.second);
                        res += e.second;
                    } else if (q.top() < e.second) {
                        res -= q.top();
                        q.pop();
                        q.emplace(e.second);
                        res += e.second;
                    }
                }
            }

            f[i] = std::max(f[i], f[j - 1] + res);
        }
    }

    cout << sum - f[nums.size()] << endl;

    return 0;
}
