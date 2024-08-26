#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, m, k;
bool g[N][N];
int s[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        std::string s;

        cin >> s;

        for (int j = 1; j <= m; j++) {
            g[i][j] = s[j - 1] == '1';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + g[i][j];
        }
    }

    int ans = std::numeric_limits<int>::max();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    if (s[k][l] - s[i - 1][l] - s[k][j - 1] + s[i - 1][j - 1] >= ::k) {
                        ans = std::min(ans, (k - i + 1) * (l - j + 1));
                    }
                }
            }
        }
    }

    cout << (ans == std::numeric_limits<int>::max() ? 0 : ans) << endl;

    return 0;
}
