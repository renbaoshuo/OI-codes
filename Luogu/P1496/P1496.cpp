#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e4 + 5;

int n, ans,
    l[N], r[N],         // 原位置
    f[N << 1];          // 染色情况（离散化以后），注意开两倍空间（左右端点）
std::vector<int> nums;  // 统计出现的数字，离散化用

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];

        // 统计一下哪些数字出现过
        nums.push_back(l[i]);
        nums.push_back(r[i]);
    }

    // 先排序才能用 std::unique 去重，两个函数都在 <algorithm> 里面定义
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());  // 去重完移除后面多余的数字
    // 可以讲一下 std::unique 跑完以后数组的特性：前面不重复且单增，后面是多余的数

    for (int i = 1; i <= n; i++) {
        // 求出离散化以后的位置
        int nl = std::lower_bound(nums.begin(), nums.end(), l[i]) - nums.begin(),
            nr = std::lower_bound(nums.begin(), nums.end(), r[i]) - nums.begin();

        // 这里用差分也可以，不过数据范围比较小，这么写也能过
        for (int j = nl; j < nr; j++) {
            f[j] = 1;
        }
    }

    for (int i = 0; i < nums.size() - 1; i++) {
        // 如果被染色就统计一下长度
        if (f[i]) ans += nums[i + 1] - nums[i];
    }

    cout << ans << endl;

    return 0;
}
