#include <iostream>
#include <fstream>

// using std::cin;
// using std::cout;
std::ifstream cin("matrix.in");
std::ofstream cout("matrix.out");
const char endl = '\n';

const int N = 505;

int n, m, t, a[N][N], s[N][N];
bool g[N][N];

int sum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            g[i][j] = a[i][j] + a[i + 1][j + 1] == a[i + 1][j] + a[i][j + 1];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + g[i][j];
        }
    }

    while (t--) {
        int x, y, k;

        cin >> x >> y >> k;

        cout << (k == 1 || sum(x, y, x + k - 2, y + k - 2) == (k - 1) * (k - 1) ? 'Y' : 'N') << endl;
    }

    return 0;
}
