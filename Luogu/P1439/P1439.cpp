#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int N = 10005;

int n, a[N], b[N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) {
                f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }
    cout << f[n][n] << endl;
    return 0;
}
