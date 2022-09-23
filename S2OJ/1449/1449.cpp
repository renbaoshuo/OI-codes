#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, m, t[N], a[N], b[N], c[N], d[N], f[N][N][2];
std::vector<std::pair<int, int>> nums{{0, 1}};

bool check(int p, int q) {
    memset(f, 0xc0, sizeof(f));
    f[0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        if (d[i]) {
            for (int j = 0; j <= m; j++) {
                f[i][j][1] = std::max({
                    f[i][j][1],
                    f[i - 1][j][0] - d[i] * p,
                    f[i - 1][j][1] - d[i] * p,
                });
            }
        } else {  // d[i] == 0
            for (int j = 0; j <= m; j++) {
                f[i][j][0] = std::max(f[i][j][0], f[i - 1][j][0]);
                f[i][j][1] = std::max(f[i][j][1], f[i - 1][j][1]);
            }
        }

        if (b[i]) {
            for (int j = t[i]; j <= m; j++) {
                f[i][j][1] = std::max({
                    f[i][j][1],
                    f[i - 1][j - t[i]][0] - b[i] * p + (a[i] + c[i]) * q,
                    f[i - 1][j - t[i]][1] - b[i] * p + (a[i] + c[i]) * q,
                });
            }
        } else {  // b[i] == 0
            for (int j = t[i]; j <= m; j++) {
                f[i][j][0] = std::max(f[i][j][0], f[i - 1][j - t[i]][0] + (a[i] + c[i]) * q);
                f[i][j][1] = std::max(f[i][j][1], f[i - 1][j - t[i]][1] + (a[i] + c[i]) * q);
            }
        }
    }

    for (int j = 0; j <= m; j++) {
        if (f[n][j][1] >= 0 || f[n][j][0] - p >= 0) return true;
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (std::__gcd(i, j) == 1) {
                nums.emplace_back(i, j);
            }
        }
    }

    std::sort(nums.begin(), nums.end(), [&](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.first * b.second < a.second * b.first;
    });

    int l = 0, r = nums.size() - 1, res = 0;

    while (l <= r) {
        int mid = l + r >> 1;

        if (check(nums[mid].first, nums[mid].second)) {
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << nums[res].first << ' ' << nums[res].second << endl;

    return 0;
}
