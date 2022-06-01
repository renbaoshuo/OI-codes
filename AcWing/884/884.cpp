#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, a[N][N];

int gauss() {
    int c, r;

    for (c = r = 1; c <= n; c++) {
        int t = r;

        for (int i = r; i <= n; i++) {
            if (a[i][c]) t = i;
        }

        if (!a[t][c]) continue;

        std::swap(a[t], a[r]);

        for (int i = r + 1; i <= n; i++) {
            if (a[i][c]) {
                for (int j = n + 1; j >= c; j--) {
                    a[i][j] ^= a[r][j];
                }
            }
        }

        r++;
    }

    if (r <= n) {
        for (int i = r; i <= n; i++) {
            if (a[i][n + 1]) {
                return -1;
            }
        }

        return 1;
    }

    for (int i = n; i; i--) {
        for (int j = i + 1; j <= n; j++) {
            a[i][n + 1] ^= a[i][j] & a[j][n + 1];
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

    switch (gauss()) {
        case 0: {
            for (int i = 1; i <= n; i++) {
                cout << a[i][n + 1] << endl;
            }

            break;
        }
        case 1: {
            cout << "Multiple sets of solutions" << endl;

            break;
        }
        case -1: {
            cout << "No solution" << endl;

            break;
        }
    }

    return 0;
}
