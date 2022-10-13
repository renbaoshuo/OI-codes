#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2505;

int n, k, s[N], e[N], w[N];
long long f[N << 1], sum;
std::vector<int> nums;
std::vector<std::pair<int, int>> g[N << 1];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> e[i] >> w[i];

        nums.emplace_back(s[i]);
        nums.emplace_back(e[i]);
        sum += w[i];
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    for (int i = 1; i <= n; i++) {
        s[i] = std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), s[i])) + 1;
        e[i] = std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), e[i])) + 1;

        g[s[i]].emplace_back(e[i], w[i]);
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
                        res += e.second - q.top();
                        q.pop();
                        q.emplace(e.second);
                    }
                }
            }

            f[i] = std::max(f[i], f[j - 1] + res);
        }
    }

    cout << sum - f[nums.size()] << endl;

    return 0;
}
