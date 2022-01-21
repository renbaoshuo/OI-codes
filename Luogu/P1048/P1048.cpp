#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int t, m, v[105], w[105], f[105][105];

int main() {
    cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= 0; j--) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                f[i][j] = std::max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    cout << f[m][t] << endl;
    return 0;
}
