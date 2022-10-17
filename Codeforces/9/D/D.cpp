#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 40;

int n, h;
long long f[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> h;

    for (int i = 0; i <= n; i++) {
        f[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < i; k++) {
                f[i][j] += f[k][j - 1] * f[i - k - 1][j - 1];
            }
        }
    }

    cout << f[n][n] - f[n][h - 1] << endl;

    return 0;
}
