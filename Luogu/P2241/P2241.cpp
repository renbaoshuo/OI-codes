#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, m;
long long ans1, ans2;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans1 += std::min(i, j);                                  // 正方形
            ans2 += static_cast<long long>(i) * j - std::min(i, j);  // 长方形 = 矩形 - 正方形
        }
    }

    cout << ans1 << ' ' << ans2 << endl;

    return 0;
}
