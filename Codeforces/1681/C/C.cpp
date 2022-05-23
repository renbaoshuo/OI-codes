#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int t, n, a[N], b[N];
std::pair<int, int> c[N];
std::vector<std::pair<int, int>> nums, ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        for (int i = 1; i <= n; i++) {
            nums.push_back(std::make_pair(a[i], b[i]));
            c[i] = std::make_pair(a[i], b[i]);
        }

        std::sort(nums.begin(), nums.end());

        bool flag = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1].second > nums[i].second) {
                cout << -1 << endl;
                flag = false;
                break;
            }
        }

        if (flag) {
            for (int i = 1; i < n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (c[i] > c[j]) {
                        ans.push_back(std::make_pair(i, j));
                        std::swap(c[i], c[j]);
                    }
                }
            }

            cout << ans.size() << endl;

            for (auto e : ans) {
                cout << e.first << ' ' << e.second << endl;
            }
        }

        nums.clear();
        ans.clear();
    }

    return 0;
}
