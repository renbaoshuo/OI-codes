#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205;

int n, m;
long long g[N][N], s[N][N], c[N], ans;

bool check(int x) {
    long long t = 0;

    for (int i = x; i <= m; i++) {
        t = std::min(t, c[i - x]);

        if (c[i] > t) return true;
    }

    return false;
}

int calc() {
    int l = 1, r = n, res = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];

            s[i][j] = s[i - 1][j] + g[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                c[k] = c[k - 1] + s[j][k] - s[i - 1][k];
            }

            ans = std::max(ans, static_cast<long long>(j - i + 1) * calc());
        }
    }

    cout << ans << endl;

    return 0;
}
