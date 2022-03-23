#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505;

int n, k, sum[N], f[N][N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = j - 1; l <= i; l++) {
                f[i][j] = std::max({f[i][j], f[i - 1][j], f[l][j - 1] + (sum[i] - sum[l])});
            }
        }
    }

    cout << f[n][k] << endl;

    return 0;
}
