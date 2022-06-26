#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205;

int n;
long long ans;
bool f[N][N];

struct node {
    int x, y, p;
} p[N];

bool check(long long x) {
    memset(f, 0x00, sizeof(f));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (1ll * p[i].p * x >= static_cast<long long>(std::abs(p[i].x - p[j].x)) + static_cast<long long>(abs(p[i].y - p[j].y))) {
                f[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (f[j][i]) {
                for (int k = 1; k <= n; k++) {
                    f[j][k] |= f[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;

        for (int j = 1; j <= n; j++) {
            cnt += f[i][j];
        }

        if (cnt == n) return true;
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].p;
    }

    long long l = 0, r = 4e9 + 5;

    while (l <= r) {
        long long mid = l + r >> 1;

        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
