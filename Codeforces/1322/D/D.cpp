#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

int n, m, l[N], s[N], c[N << 1], f[N << 1][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n + m; i++) {
        cin >> c[i];
    }

    memset(f, 0xc0, sizeof(f));

    for (int i = 1; i <= n + m; i++) {
        f[i][0] = 0;
    }

    for (int i = n; i; i--) {
        for (int j = n; j; j--) {
            f[l[i]][j] = std::max(f[l[i]][j], f[l[i]][j - 1] + c[l[i]] - s[i]);
        }

        for (int j = l[i]; j <= n + m; j++) {
            for (int k = 0; k <= (n >> (j - l[i])); k++) {
                f[j + 1][k >> 1] = std::max(f[j + 1][k >> 1], f[j][k] + (k >> 1) * c[j + 1]);
            }
        }
    }

    cout << f[n + m][0] << endl;

    return 0;
}
