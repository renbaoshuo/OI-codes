#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505;

int n, k;
std::pair<int, unsigned int> p[N], q[N];
double f[N][N], g[N][N], ans = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    std::sort(p + 1, p + 1 + n, [&](auto a, auto b) -> bool {
        return a.second < b.second;
    });

    for (int i = 1; i <= n; i++) {
        q[i] = p[i];
    }

    // 预处理 i ~ n 中 a_i 的前 j 小之和
    for (int i = n; i; i--) {
        std::sort(q + i, q + 1 + n, [&](auto a, auto b) -> bool {
            return a.first < b.first;
        });

        for (int j = i; j <= n; j++) {
            g[i][j - i + 1] = g[i][j - i] + q[j].first;
        }
    }

    for (int t = 0; t < k; t++) {  // 枚举招纳协作者的数量
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= t; j++) {
                f[i][j] = 1e9;
            }
        }

        f[0][0] = 0;  // 演讲前耗时为 0

        for (int i = 1; i <= k; i++) {
            // 还未招协作者的时候直接从上一次转移
            f[i][0] = f[i - 1][0] + static_cast<double>(p[i].first) / (t + 1);  // 还要加上 Rie 本人

            for (int j = 1; j <= t; j++) {
                f[i][j] = std::min(
                    f[i - 1][j - 1] + static_cast<double>(p[i].second) / j,    // 需要招协作者的立即演讲
                    f[i - 1][j] + static_cast<double>(p[i].first) / (t + 1));  // 不招协作者的在招满后再演讲
            }
        }

        for (int i = 0; i <= k; i++) {
            ans = std::min(ans, f[i][t] + g[i + 1][k - i] / (t + 1));  // 增加协作者耗时 + 纯演讲耗时
        }
    }

    cout << std::fixed << std::setprecision(15) << ans << endl;

    return 0;
}
