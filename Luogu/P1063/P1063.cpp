#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105 << 1;

int n, a[N], f[N][N], ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = len; r <= n << 1; l++, r++) {
            for (int k = l; k < r; k++) {
                f[l][r] = std::max(f[l][r], f[l][k] + f[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, f[i][n + i - 1]);
    }

    cout << ans << endl;

    return 0;
}
