#include <cstdio>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

int t, n, a[N][N], sum, ans;

int main() {
    cin >> t;
    while (t--) {
        sum = 0;
        ans = 0x3f3f3f3f;

        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%1d", &a[i][j]);
                sum += a[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                cnt += a[(i + j - 1) % n + 1][j];
            }
            ans = std::min(ans, n - cnt + sum - cnt);
        }

        cout << ans << endl;
    }

    return 0;
}
