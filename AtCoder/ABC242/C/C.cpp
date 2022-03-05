#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int mod = 998244353;

int n;
long long f[1000005][10], ans;

int main() {
    cin >> n;
    if (n == 1) {
        cout << 9 << endl;
        exit(0);
    }
    for (int i = 1; i <= 9; i++) {
        f[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            f[i][j] = f[i - 1][j];
            if (j > 1) {
                f[i][j] += f[i - 1][j - 1];
            }
            if (j < 9) {
                f[i][j] += f[i - 1][j + 1];
            }
            f[i][j] %= mod;
        }
    }
    for (int i = 0; i <= 9; i++) {
        ans += f[n][i];
    }
    cout << ans % mod << endl;
    return 0;
}
