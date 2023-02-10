#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

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
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, k; i <= n; i++) {
        cin >> k;

        for (int j = 1, x; j <= k; j++) {
            cin >> x;

            a[i][x] = 1;
        }

        if (k % 2) {
            a[i][i] = 1;
            a[i][n + 1] = 1;
        }
    }

    if (gauss() != 0) {
        cout << -1 << endl;
    } else {
        std::vector<int> ans;

        for (int i = 1; i <= n; i++) {
            if (a[i][n + 1]) {
                ans.push_back(i);
            }
        }

        cout << ans.size() << endl;

        for (int x : ans) {
            cout << x << ' ';
        }

        cout << endl;
    }

    return 0;
}
