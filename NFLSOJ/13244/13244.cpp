// #include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <utility>
#include <vector>

// using std::cin;
// using std::cout;
std::ifstream cin("rewrite.in");
std::ofstream cout("rewrite.out");
const char endl = '\n';

const int N = 5005;

int n;
long long f[N][N][2];
bool flag = false;
std::pair<int, int> a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, l, r; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    if (n % 2) {
        flag = true;
    } else {
        a[++n] = std::make_pair(0, 0);
    }

    memset(f, 0x3f, sizeof(f));
    std::sort(a + 1, a + n + 1, [&](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) -> bool { return lhs.second - lhs.first > rhs.second - rhs.first; });

    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n || flag) {
            for (int j = 0; j <= i; j++) {
                f[i][j][1] = f[i - 1][j][0] + static_cast<long long>(n >> 1) * (a[i].second - a[i].first);
            }
        }

        for (int j = 0; j <= i; j++) {
            if (j) {
                f[i][j][0] = std::min(f[i][j][0], f[i - 1][j - 1][0] + static_cast<long long>(j - 1) * (a[i].second - a[i].first) + a[i].second);
                f[i][j][1] = std::min(f[i][j][1], f[i - 1][j - 1][1] + static_cast<long long>(j - 1) * (a[i].second - a[i].first) + a[i].second);
            }

            if (j != i) {
                f[i][j][0] = std::min(f[i][j][0], f[i - 1][j][0] + static_cast<long long>(i - j - 1) * (a[i].second - a[i].first) - a[i].first);
                f[i][j][1] = std::min(f[i][j][1], f[i - 1][j][1] + static_cast<long long>(i - j - 2) * (a[i].second - a[i].first) - a[i].first);
            }
        }
    }

    cout << f[n][n >> 1][1] << endl;

    return 0;
}
