#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int c, h, b, f[N][N][2], ans = std::numeric_limits<int>::max();
std::pair<int, int> a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(f, 0x3f, sizeof(f));

    cin >> c >> h >> b;

    for (int i = 1; i <= c; i++) {
        cin >> a[i].first >> a[i].second;
    }

    std::sort(a + 1, a + 1 + c);

    f[0][c][0] = f[0][c][1] = 0;

    for (int i = 1; i <= c; i++) {
        for (int j = c; j >= i; j--) {
            f[i][j][0] = std::min({
                std::max(f[i - 1][j][0] + a[i].first - a[i - 1].first, a[i].second),
                std::max(f[i][j + 1][1] + a[j + 1].first - a[i].first, a[i].second),
            });

            f[i][j][1] = std::min({
                std::max(f[i - 1][j][0] + a[j].first - a[i - 1].first, a[j].second),
                std::max(f[i][j + 1][1] + a[j + 1].first - a[j].first, a[j].second),
            });
        }
    }

    for (int i = 1; i <= c; i++) {
        ans = std::min(ans, std::min(f[i][i][0], f[i][i][1]) + std::abs(b - a[i].first));
    }

    cout << ans << endl;

    return 0;
}
