#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, a[N], b[N];
std::vector<int> nums;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nums.push_back(a[i]);
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    for (int i = 1; i <= n; i++) {
        a[i] = std::lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
    }

    for (int i = 1, l, r, x = 0; i <= m; i++) {
        memset(b, 0x00, sizeof(b));

        std::pair<int, int> ans;

        cin >> l >> r;
        l = (l + x - 1) % n + 1;
        r = (r + x - 1) % n + 1;
        if (l > r) std::swap(l, r);

        for (int i = l; i <= r; i++) b[a[i]]++;

        for (int i = 0; i < nums.size(); i++) {
            if (b[i] > ans.first) {
                ans = std::make_pair(b[i], i);
            }
        }

        cout << (x = nums[ans.second]) << endl;
    }

    return 0;
}
