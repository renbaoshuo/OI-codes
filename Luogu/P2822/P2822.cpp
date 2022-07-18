#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

int t, k, n, m, c[N][N], f[N][N];

int main() {
    cin >> t >> k;

    c[1][1] = 1;
    for (int i = 1; i <= 2000; i++) {
        c[i][0] = c[i][i] = 1;
    }

    for (int i = 2; i <= 2000; i++) {
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
        }
    }

    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
            if (!c[i][j]) f[i][j]++;
        }

        f[i][i + 1] = f[i][i];
    }

    while (t--) {
        cin >> n >> m;

        cout << f[n][std::min(n, m)] << endl;
    }

    return 0;
}
