#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

int n, f[N][N], ans;
std::pair<int, int> a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    std::sort(a + 1, a + 1 + n, std::greater<>());
    memset(f, 0xc0, sizeof(f));

    f[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = std::max(f[i - 1][j], f[i - 1][std::max(j - a[i].first, 0) + 1] + a[i].second);
        }
    }

    for (int i = 0; i <= n; i++) {
        ans = std::max(ans, f[n][i]);
    }

    cout << ans << endl;

    return 0;
}
