#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105 << 1;

int n, a[N], sum[N], f1[N][N], f2[N][N], ans1, ans2;

int main() {
    std::ios::sync_with_stdio(false);

    memset(f1, 0x3f, sizeof(f1));
    ans1 = 0x3f3f3f3f;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i < (n << 1); i++) {
        sum[i] = sum[i - 1] + a[i];
        f1[i][i] = f2[i][i] = 0;
    }

    for (int i = 2; i <= n; i++) {
        for (int l = 1, r = i; r < (n << 1); l++, r++) {
            for (int k = l; k < r; k++) {
                f1[l][r] = std::min(f1[l][r], f1[l][k] + f1[k + 1][r]);
                f2[l][r] = std::max(f2[l][r], f2[l][k] + f2[k + 1][r]);
            }
            f1[l][r] += sum[r] - sum[l - 1];
            f2[l][r] += sum[r] - sum[l - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        ans1 = std::min(ans1, f1[i][i + n - 1]);
        ans2 = std::max(ans2, f2[i][i + n - 1]);
    }

    cout << ans1 << endl
         << ans2 << endl;

    return 0;
}
