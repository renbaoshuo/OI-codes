#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 125;

int n, a[N][N], s[N][N],
    ans = std::numeric_limits<int>::min();

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // 二维前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    // 枚举矩形的左上角和右下角
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= n; y2++) {
                    ans = std::max(ans, s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
