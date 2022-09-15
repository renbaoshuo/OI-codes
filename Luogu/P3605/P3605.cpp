#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, p[N], c[N], ans[N];
std::vector<int> nums, g[N];

inline int lowbit(int x) {
    return x & -x;
}

inline void add(int x, int y) {
    for (; x <= n; x += lowbit(x)) c[x] += y;
}

inline int sum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}

void dfs(int u) {
    ans[u] -= sum(n) - sum(p[u]);

    for (int v : g[u]) {
        dfs(v);
    }

    ans[u] += sum(n) - sum(p[u]);

    add(p[u], 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];

        nums.emplace_back(p[i]);
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    for (int i = 1; i <= n; i++) {
        p[i] = std::lower_bound(nums.begin(), nums.end(), p[i]) - nums.begin() + 1;
    }

    for (int i = 2, x; i <= n; i++) {
        cin >> x;

        g[x].emplace_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
