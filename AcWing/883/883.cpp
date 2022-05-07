#include <cmath>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss() {
    int c, r;

    for (c = 1, r = 1; c <= n; c++) {
        // 找到绝对值最大的一行
        int t = r;
        for (int i = r; i <= n; i++) {
            if (std::abs(a[i][c]) > std::abs(a[t][c])) t = i;
        }

        // 非零
        if (std::abs(a[t][c]) < eps) continue;

        // 将该行移至顶部
        for (int i = c; i <= n + 1; i++) {
            std::swap(a[t][i], a[r][i]);
        }

        // 将该行第一个非零的数变成 1
        for (int i = n + 1; i >= c; i--) {
            a[r][i] /= a[r][c];
        }

        // 将下方所有行的第 c 列变成 0
        for (int i = r + 1; i <= n; i++) {
            if (std::abs(a[i][c]) > eps) {  // 非零
                for (int j = n + 1; j >= c; j--) {
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }

        r++;
    }

    if (r <= n) {
        for (int i = r; i <= n; i++) {
            if (std::abs(a[i][n + 1]) > eps)
                // 无解
                return -1;
        }

        // 无穷多组解
        return 1;
    }

    // 将系数矩阵化为对角矩阵
    for (int i = n; i; i--) {
        for (int j = i + 1; j <= n; j++) {
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
        }
    }

    // 有解
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            cin >> a[i][j];
        }
    }

    int r = gauss();

    if (r == 0) {
        for (int i = 1; i <= n; i++) {
            if (std::abs(a[i][n + 1]) < eps) a[i][n + 1] = 0;
            cout << std::fixed << std::setprecision(2) << a[i][n + 1] << endl;
        }
    } else if (r == 1) {
        cout << "Infinite group solutions" << endl;
    } else {  // r == -1
        cout << "No solution" << endl;
    }

    return 0;
}
