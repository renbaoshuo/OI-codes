#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3005;

int n, k, p, w[N], f[N][N][2], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    memset(f, 0xc0, sizeof(f));
    f[0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> p;

        std::copy_n(std::istream_iterator<int>(cin), p, w + 1);

        for (int j = k - 1; j >= 0; j--) {
            f[i][j][0] = f[i - 1][j][0];
            f[i][j][1] = f[i - 1][j][1];

            if (j + p <= k) {  // 全取
                f[i][j + p][0] = std::max(f[i][j + p][0], f[i - 1][j][0] + w[p]);
                f[i][j + p][1] = std::max(f[i][j + p][1], f[i - 1][j][1] + w[p]);
            }

            for (int l = 1; l < p && l <= k - j; l++) {
                f[i][j + l][1] = std::max(f[i][j + l][1], f[i - 1][j][0] + w[l]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            ans = std::max(ans, f[i][j][0]);
        }

        ans = std::max(ans, f[i][k][1]);
    }

    cout << ans << endl;

    return 0;
}
