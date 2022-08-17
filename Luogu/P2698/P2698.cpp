#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, d, ans = std::numeric_limits<int>::max();
std::pair<int, int> points[N];
std::set<int> set;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;

    for (int i = 1; i <= n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    std::sort(points + 1, points + 1 + n, [](auto a, auto b) -> bool {
        return a.second < b.second;
    });

    int lst = 1;
    for (int i = 1; i <= n; i++) {
        int pos = std::upper_bound(points + 1, points + 1 + n, std::make_pair(0, points[i].second - d), [](auto a, auto b) -> bool {
                      return a.second < b.second;
                  })
                - points;

        for (int j = lst; j < pos; j++) {
            set.insert(points[j].first);
        }

        lst = pos;

        auto it1 = set.lower_bound(points[i].first),
             it2 = set.upper_bound(points[i].first);

        if (it1 != set.begin()) {
            ans = std::min(ans, std::abs(points[i].first - *--it1));
        }

        if (it2 != set.end()) {
            ans = std::min(ans, std::abs(points[i].first - *it2));
        }
    }

    cout << (ans == std::numeric_limits<int>::max() ? -1 : ans) << endl;

    return 0;
}
