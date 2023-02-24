#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

std::vector<std::pair<long long, int>> divide(long long x) {
    std::vector<std::pair<long long, int>> res;

    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;

            while (x % i == 0) x /= i, cnt++;

            res.emplace_back(i, cnt);
        }
    }

    if (x > 1) res.emplace_back(x, 1);

    return res;
}

void solve() {
    long long n;
    bool flag = false;

    cin >> n;

    auto nums = divide(n);

    std::transform(nums.begin(), nums.end(), nums.begin(), [&](const std::pair<long long, int> &o) -> std::pair<long long, int> {
        return {o.first, o.second << 1};
    });

    std::function<bool(long long)> check = [&](long long x) -> bool {
        long long t = x * x - n * n / x;

        if (t % 3) return false;

        long long l = 1, r = x / 2 + 1;

        while (l <= r) {
            long long mid = (l + r) >> 1;

            if (mid * (x - mid) == t / 3) {
                cout << x - mid << ' ' << mid << endl;

                return true;
            }

            if (mid * (x - mid) > t / 3) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    };

    std::function<void(long long, int)> dfs = [&](long long val, int pos) -> void {
        if (flag) return;

        if (pos == nums.size()) {
            if (check(val)) flag = true;

            return;
        }

        for (int i = 0; i <= nums[pos].second; i++) {
            dfs(val * std::pow(nums[pos].first, i), pos + 1);
        }
    };

    dfs(1, 0);

    if (!flag) cout << "impossible" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) solve();

    return 0;
}
