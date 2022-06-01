#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e6 + 5;

int n, m, x[N], y[N], a[N], p, nums[N];
char op[N];

long long c1[N], c2[N];

inline int lowbit(int x) {
    return x & -x;
}

void add(long long *c, int x, int y) {
    for (; x <= n + m; x += lowbit(x)) c[x] += y;
}

long long sum(long long *c, int x) {
    long long ans = 0;
    for (; x; x -= lowbit(x)) ans += c[x];
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> op[i] >> x[i] >> y[i];

        nums[++p] = y[i];
    }

    std::sort(nums + 1, nums + 1 + p);
    p = std::unique(nums + 1, nums + 1 + p) - nums - 1;

    for (int i = 1, k; i <= m; i++) {
        y[i] = std::lower_bound(nums + 1, nums + 1 + p, y[i]) - nums;
        if (op[i] == 'U') {
            if (k = a[x[i]]) {
                add(c1, k, -1);
                add(c2, k, -nums[k]);
            }
            k = a[x[i]] = y[i];
            add(c1, k, 1);
            add(c2, k, nums[k]);
        } else {  // op[i] == 'Z'
            int c = sum(c1, p) - sum(c1, y[i] - 1);
            long long s = sum(c2, y[i] - 1);
            cout << (s >= 1ll * (x[i] - c) * nums[y[i]] ? "TAK" : "NIE") << endl;
        }
    }

    return 0;
}
