#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int n, m, q, c, b[1005][1005];

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            b[i][j] += c;
            b[i + 1][j] -= c;
            b[i][j + 1] -= c;
            b[i + 1][j + 1] += c;
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        b[x1][y1] += c;
        b[x2 + 1][y1] -= c;
        b[x1][y2 + 1] -= c;
        b[x2 + 1][y2 + 1] += c;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
