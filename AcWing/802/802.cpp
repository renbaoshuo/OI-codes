#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
#define endl '\n'

int n, m, x, c, l, r, data[300005], sum[300005];
std::vector<int> nums;
std::vector<std::pair<int, int>> adds, queries;

inline int find(int x) {
    auto pos = std::lower_bound(nums.begin(), nums.end(), x);
    return pos == nums.end() || *pos != x ? 0 : pos - nums.begin() + 1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x >> c;
        nums.push_back(x);
        adds.push_back(std::make_pair(x, c));
    }
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        queries.push_back(std::make_pair(l, r));
        nums.push_back(l);
        nums.push_back(r);
    }
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    for (const auto& add : adds) {
        data[find(add.first)] += add.second;
    }
    for (int i = 1; i <= nums.size(); i++) {
        sum[i] = sum[i - 1] + data[i];
    }
    for (const auto& query : queries) {
        cout << sum[find(query.second)] - sum[find(query.first) - 1] << endl;
    }
    return 0;
}
