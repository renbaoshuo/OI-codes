#include <iostream>
#include <cstring>
#include <deque>
#include <tuple>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

int n, m, w, f[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(f, 0xcf, sizeof(f));

    cin >> n >> m >> w;

    for (int i = 1; i <= n; i++) {
        f[i][0] = 0;

        int ap, bp, as, bs;

        cin >> ap >> bp >> as >> bs;

        // [2]: 从 0 张开始买入
        for (int j = 0; j <= as; j++) {
            f[i][j] = -j * ap;
        }

        // [1]: 不操作
        for (int j = 0; j <= m; j++) {
            f[i][j] = std::max(f[i][j], f[i - 1][j]);
        }

        if (i - w - 1 > 0) {
            // [3]: 买入
            std::deque<int> q1;
            for (int j = 0; j <= m; j++) {
                while (!q1.empty() && q1.front() < j - as) q1.pop_front();
                while (!q1.empty() && f[i - w - 1][q1.back()] + q1.back() * ap <= f[i - w - 1][j] + j * ap) q1.pop_back();
                q1.push_back(j);
                f[i][j] = std::max(f[i][j], f[i - w - 1][q1.front()] - (j - q1.front()) * ap);
            }

            // [4]: 卖出
            std::deque<int> q2;
            for (int j = m; ~j; j--) {
                while (!q2.empty() && q2.front() > j + bs) q2.pop_front();
                while (!q2.empty() && f[i - w - 1][q2.back()] + q2.back() * bp <= f[i - w - 1][j] + j * bp) q2.pop_back();
                q2.push_back(j);
                f[i][j] = std::max(f[i][j], f[i - w - 1][q2.front()] + (q2.front() - j) * bp);
            }
        }
    }

    cout << f[n][0] << endl;

    return 0;
}
