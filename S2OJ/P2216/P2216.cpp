#include <iostream>
#include <deque>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int a, b, n, g[N][N],
    ans = std::numeric_limits<int>::max();
// row_min[i][j] 表示第 i 行的第 j 个元素到第 j + n - 1 个元素的最小值（长度 n）
int row_min[N][N], row_max[N][N];
int col_min[N][N], col_max[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> n;

    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            cin >> g[i][j];

    // 先处理每行的最大、最小值
    for (int i = 1; i <= a; i++) {
        std::deque<int> q_min, q_max;

        for (int j = 1; j <= b; j++) {
            while (!q_min.empty() && g[i][q_min.back()] >= g[i][j]) q_min.pop_back();
            q_min.push_back(j);
            if (q_min.front() <= j - n) q_min.pop_front();

            while (!q_max.empty() && g[i][q_max.back()] <= g[i][j]) q_max.pop_back();
            q_max.push_back(j);
            if (q_max.front() <= j - n) q_max.pop_front();

            if (j >= n) {
                row_min[i][j - n + 1] = g[i][q_min.front()];
                row_max[i][j - n + 1] = g[i][q_max.front()];
            }
        }
    }

    // 再基于上面的结果处理每列的最大、最小值
    for (int j = 1; j <= b; j++) {
        std::deque<int> q_min, q_max;

        for (int i = 1; i <= a; i++) {
            while (!q_min.empty() && row_min[q_min.back()][j] >= row_min[i][j]) q_min.pop_back();
            q_min.push_back(i);
            if (q_min.front() <= i - n) q_min.pop_front();

            while (!q_max.empty() && row_max[q_max.back()][j] <= row_max[i][j]) q_max.pop_back();
            q_max.push_back(i);
            if (q_max.front() <= i - n) q_max.pop_front();

            if (i >= n) {
                col_min[i - n + 1][j] = row_min[q_min.front()][j];
                col_max[i - n + 1][j] = row_max[q_max.front()][j];
            }
        }
    }

    for (int i = 1; i <= a - n + 1; i++) {
        for (int j = 1; j <= b - n + 1; j++) {
            ans = std::min(ans, col_max[i][j] - col_min[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}
