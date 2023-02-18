#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;
const int mod = 998244353;

int n, a[N], p[N], f[N][N][N];
std::vector<std::pair<int, int>> nums;

int solve(int l, int r, int x) {
    if (x == 0) return 1;
    if (l == r) return 1;
    if (f[l][r][x] != -1) return f[l][r][x];

    int pos = std::find(p + l, p + r + 1, x) - p;

    if (pos > r) {
        return f[l][r][x] = solve(l, r, x - 1);
    }

    int res = 0;

    for (int i = pos; i <= r; i++) {
        if (p[i] <= x) {
            res = (res + static_cast<long long>(solve(l, i, x - 1)) * solve(i + 1, r, x) % mod) % mod;
        }
    }

    return f[l][r][x] = res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        nums.emplace_back(a[i], i);
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    for (int i = 1; i <= n; i++) {
        p[i] = std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), std::pair<int, int>{a[i], i}));
    }

    memset(f, 0xff, sizeof(f));

    cout << solve(1, n, n) << endl;

    return 0;
}
