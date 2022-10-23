#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 255;

int t, n, a[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 1; i <= n << 1; i++) {
            for (int j = 1; j <= n << 1; j++) {
                cin >> a[i][j];
            }
        }

        long long ans = 0;
        for (int i = n + 1; i <= n + n; i++) {
            for (int j = n + 1; j <= n + n; j++) {
                ans += a[i][j];
            }
        }

        cout << ans + std::min({a[1][n + 1], a[1][n + n], a[n][n + 1], a[n][n + n], a[n + 1][n], a[n + 1][1], a[n + n][1], a[n + n][n]}) << endl;
    }

    return 0;
}
