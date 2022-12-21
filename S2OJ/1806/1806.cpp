#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 155;

int n, v[N], a[N];
int f[N][N], g[N][N], h[N][N][N];
std::vector<int> nums, pos[N << 1];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        nums.emplace_back(a[i]);
        nums.emplace_back(a[i] + 1);
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    for (int i = 1; i <= n; i++) {
        a[i] = std::lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin() + 1;
        pos[a[i]].emplace_back(i);
    }

    memset(f, 0xcf, sizeof(f));
    memset(g, 0xcf, sizeof(g));
    memset(h, 0xcf, sizeof(h));

    for (int i = 1; i <= n; i++) {
        f[i][i] = std::max(0, v[1]);
        g[i][i] = v[1];
        g[i][i - 1] = h[i][i][1] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = len; r <= n; l++, r++) {
            for (int k = 2; k <= len; k++) {
                for (int p : pos[a[l] + 1]) {
                    if (l <= p && p <= r) {
                        h[l][r][k] = std::max(h[l][r][k], h[p][r][k - 1] + g[l + 1][p - 1]);
                    }
                }

                for (int p : pos[a[r] + 1]) {
                    if (l <= p && p <= r) {
                        h[l][r][k] = std::max(h[l][r][k], h[l][p][k - 1] + g[p + 1][r - 1]);
                    }
                }

                g[l][r] = std::max(g[l][r], h[l][r][k] + v[k]);
            }

            for (int k = l; k < r; k++) {
                f[l][r] = std::max(f[l][r], f[l][k] + f[k + 1][r]);
                g[l][r] = std::max(g[l][r], g[l][k] + g[k + 1][r]);
            }

            f[l][r] = std::max(f[l][r], g[l][r]);
        }
    }

    cout << f[1][n] << endl;

    return 0;
}
