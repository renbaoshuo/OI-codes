#include <cmath>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss() {
    int r, c;

    for (r = c = 1; c <= n; c++) {
        int t = r;

        for (int i = r; i <= n; i++) {
            if (std::abs(a[i][c]) > std::abs(a[t][c])) t = i;
        }

        if (std::abs(a[t][c]) < eps) continue;

        std::swap(a[t], a[c]);

        for (int i = n + 1; i >= c; i--) {
            a[r][i] /= a[r][c];
        }

        for (int i = r + 1; i <= n; i++) {
            if (std::abs(a[i][c]) > eps) {
                for (int j = n + 1; j >= c; j--) {
                    a[i][j] -= a[i][c] * a[r][j];
                }
            }
        }

        r++;
    }

    if (r <= n) return -1;

    for (int i = n; i; i--) {
        for (int j = i + 1; j <= n; j++) {
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
        }
    }

    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            cin >> a[i][j];
        }
    }

    if (!gauss()) {
        for (int i = 1; i <= n; i++) {
            cout << std::fixed << std::setprecision(2) << a[i][n + 1] << endl;
        }
    } else {
        cout << "No Solution" << endl;
    }

    return 0;
}
