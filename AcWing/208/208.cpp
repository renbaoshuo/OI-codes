#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 35;

int t, n, a[N][N];

int gauss() {
    int r, c;
    for (r = c = 1; c <= n; c++) {
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

    int res = 1;

    if (r <= n) {
        for (int i = r; i <= n; i++) {
            if (a[i][n + 1]) return -1;
            res <<= 1;
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        memset(a, 0x00, sizeof(a));

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i][n + 1];
        }

        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            a[i][n + 1] ^= x;
            a[i][i] = 1;
        }

        int x, y;
        while (cin >> x >> y, x || y) a[y][x] = 1;

        int r = gauss();

        if (r == -1) {
            cout << "Oh,it's impossible~!!" << endl;
        } else {
            cout << r << endl;
        }
    }

    return 0;
}
