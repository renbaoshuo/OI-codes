#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 305;

int n, a[N], sum[N], f[N][N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 2; i <= n; i++) {
        for (int l = 1, r = i; r <= n; l++, r++) {
            f[l][r] = 0x3f3f3f3f;
            for (int k = l; k < r; k++) {
                f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }

    cout << f[1][n] << endl;

    return 0;
}
