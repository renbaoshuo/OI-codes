#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, m, k;
int a[N][N], b[N][N], c[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= m; l++) {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cout << c[i][j] << ' ';
        }

        cout << endl;
    }

    return 0;
}
