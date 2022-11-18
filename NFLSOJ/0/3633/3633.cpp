// #include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <utility>

// using std::cin;
// using std::cout;
std::ifstream cin("pair.in");
std::ofstream cout("pair.out");
const char endl = '\n';

const int N = 2e5 + 5,
          M = (1 << 8) + 5;

int n, q, max_pre[M][N], max_suf[M][N], max_val[M][M][(1 << 9) + 5][2];
std::pair<int, int> a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    std::sort(a + 1, a + 1 + n, [&](const auto &lhs, const auto &rhs) -> bool { return (lhs.first & 0x1ff) < (rhs.first & 0x1ff); });

    for (int i = 0; i < 1 << 8; i++) {
        max_pre[i][0] = max_suf[i][n + 1] = 0;

        for (int j = 1; j <= n; j++) {
            max_pre[i][j] = std::max(max_pre[i][j - 1], (i + (a[j].first >> 9)) ^ (a[j].second >> 9));
        }

        for (int j = n; j; j--) {
            max_suf[i][j] = std::max(max_suf[i][j + 1], (i + (a[j].first >> 9)) ^ (a[j].second >> 9));
        }
    }

    memset(max_val, 0xff, sizeof(max_val));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 0x1ff; j++) {
            max_val[a[i].first >> 9][a[i].second >> 9][j][j + (a[i].first & 0x1ff) >= 0x200] = std::max(
                max_val[a[i].first >> 9][a[i].second >> 9][j][j + (a[i].first & 0x1ff) >= 0x200],
                ((j + a[i].first) ^ a[i].second) & 0x1ff);
        }
    }

    cin >> q;

    while (q--) {
        int t, l = 1, r = n, res = 1;

        cin >> t;

        while (l <= r) {
            int mid = l + r >> 1;

            if ((t & 0x1ff) + (a[mid].first & 0x1ff) < 0x200) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }

        int high = std::max(max_pre[t >> 9][res], max_suf[(t >> 9) + 1][res + 1]),
            low = -1;

        for (int i = 0; i <= 0xff; i++) {
            int j = (high ^ i) - (t >> 9);

            if (0 <= j && j <= 0xff) {
                low = std::max(low, max_val[j][i][t & 0x1ff][0]);
            }

            if (0 <= j - 1 && j - 1 <= 0xff) {
                low = std::max(low, max_val[j - 1][i][t & 0x1ff][1]);
            }
        }

        cout << (high << 9 | low) << endl;
    }

    return 0;
}
