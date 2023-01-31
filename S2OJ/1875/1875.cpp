#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const long long INF = 0x3f3f3f3f'3f3f3f3f;

int n, k;
std::vector<std::pair<long long, long long>> points;

bool check(long long x) {
    int cnt = 0;
    std::queue<std::pair<long long, long long>> q;
    std::set<std::pair<long long, long long>> set;

    for (auto o : points) {
        while (!q.empty() && q.front().first + x < o.first) {
            set.erase({q.front().second, q.front().first});
            q.pop();
        }

        cnt += std::distance(set.lower_bound({o.second - x, -INF}), set.upper_bound({o.second + x, INF}));

        if (cnt >= k) return true;

        set.emplace(o.second, o.first);
        q.emplace(o);
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;

        points.emplace_back(x + y, x - y);
    }

    std::sort(points.begin(), points.end());

    long long l = 0,
              r = INF,
              res;

    while (l <= r) {
        long long mid = (l + r) >> 1;

        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    std::vector<long long> ans;
    std::queue<std::pair<long long, long long>> q;
    std::set<std::pair<long long, long long>> set;

    for (auto o : points) {
        while (!q.empty() && q.front().first + res - 1 < o.first) {
            set.erase({q.front().second, q.front().first});
            q.pop();
        }

        std::transform(
            set.lower_bound({o.second - res + 1, -INF}),
            set.upper_bound({o.second + res - 1, INF}),
            std::back_inserter(ans),
            [&](const std::pair<long long, long long>& item) -> long long {
                return std::max(std::abs(item.first - o.second), o.first - item.second);
            });

        set.emplace(o.second, o.first);
        q.emplace(o);
    }

    std::sort(ans.begin(), ans.end());
    ans.resize(k, res);

    for (auto x : ans) cout << x << endl;

    return 0;
}

