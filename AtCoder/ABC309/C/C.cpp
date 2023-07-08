#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

int n, k;
std::pair<int, int> a[N];
std::vector<int> nums;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;

        nums.emplace_back(a[i].first);
    }

    std::sort(a + 1, a + 1 + n, [](std::pair<int, int> x, std::pair<int, int> y) { return x.first < y.first; });
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    for (int i = 1; i <= n; i++) {
        a[i].first = std::lower_bound(nums.begin(), nums.end(), a[i].first) - nums.begin() + 1;
    }

    long long sum = std::accumulate(a + 1, a + 1 + n, 0ll, [](long long x, std::pair<int, int> y) { return x + y.second; });

    if (sum <= k) {
        cout << 1 << endl;

        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        sum -= a[i].second;

        if (sum <= k) {
            cout << nums[a[i].first - 1] + 1 << endl;

            exit(0);
        }
    }

    return 0;
}
