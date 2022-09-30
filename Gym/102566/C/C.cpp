#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int t, n, a[N];
std::pair<int, int> c[N];

void insert(int x, std::pair<int, int> y) {
    for (; x < N; x += x & -x) c[x] = std::max(c[x], y);
}

std::pair<int, int> query(int x) {
    std::pair<int, int> ans{0, 0};
    for (; x; x -= x & -x) ans = std::max(ans, c[x]);
    return ans;
}

void clear(int x) {
    for (; x < N; x += x & -x) c[x] = std::make_pair(0, 0);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        int ans = 0, min = std::numeric_limits<int>::max();
        std::vector<int> nums;

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            nums.emplace_back(a[i]);
        }

        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        for (int i = 1; i <= n; i++) {
            a[i] = std::lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin() + 1;
        }

        for (int i = 1; i <= n; i++) {
            auto res = query(a[i]);

            res.first++;
            if (res.first == 1) res.second = i;
            if (res.first > ans) {
                ans = res.first;
                min = i - res.second + 1 - res.first;
            } else if (res.first == ans) {
                min = std::min(min, i - res.second + 1 - res.first);
            }

            insert(a[i], res);
        }

        for (int i = 1; i <= n; i++) {
            clear(a[i]);
        }

        cout << ans << ' ' << min << endl;
    }

    return 0;
}
