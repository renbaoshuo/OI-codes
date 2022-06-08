#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

// f[当前位置][上一组长度]
int n, a[N], s[N], f[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = n; i; i--) {
        s[i] = s[i + 1] + a[i];
    }

    for (int i = n; i; i--) {
        for (int j = 1, k = 1; j <= n; j++, k += 2) {
            f[i][j] = f[i][j - 1];

            if (k <= n - i + 1) {
                f[i][j] = std::max(f[i][j], s[i] - f[i + k][k]);
            }

            if (k + 1 <= n - i + 1) {
                f[i][j] = std::max(f[i][j], s[i] - f[i + k + 1][k + 1]);
            }
        }
    }

    cout << f[1][1] << endl;

    return 0;
}
