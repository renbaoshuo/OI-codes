#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 100005;

int n, k, w[16], sum[N], f[0xffff + 5], ans;
bool flag;

int find(int x, int y) {
    int l = f[x],
        r = std::min(n, f[x] + w[y]);  // 优化：每个物品的最小价值为 1
    int res = l;

    while (l <= r) {
        int mid = l + r >> 1;
        if (sum[mid] - sum[f[x]] <= w[y]) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> w[i];
    }

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    for (int i = 0; i < 1 << k; i++) {
        for (int j = 0; j < k; j++) {
            if ((i >> j) & 1) continue;
            f[i | (1 << j)] = std::max(f[i | (1 << j)], find(i, j));
        }

        if (f[i] == n) {  // 全部购买完
            flag = true;
            int cnt = 0;

            for (int j = 0; j < k; j++) {
                if (!((i >> j) & 1)) cnt += w[j];
            }

            ans = std::max(ans, cnt);
        }
    }

    if (flag) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
