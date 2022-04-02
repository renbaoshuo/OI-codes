#include <algorithm>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, m, f[N][N];
std::string a, b;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> a >> b;

    a = ' ' + a;
    b = ' ' + b;

    n = a.size() - 1;
    m = b.size() - 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = std::max({f[i][j], f[i - 1][j], f[i][j - 1]});
            if (a[i] == b[j]) f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }

    cout << f[n][m] << endl;

    return 0;
}
