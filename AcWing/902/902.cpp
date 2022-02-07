#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
#define endl '\n'

const int N = 1005;

int n, m, f[N][N];
char a[N], b[N];

int main() {
    cin >> n >> a + 1 >> m >> b + 1;
    for (int i = 1; i <= n; i++) {
        f[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        f[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = std::min({f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + (a[i] != b[j])});
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
