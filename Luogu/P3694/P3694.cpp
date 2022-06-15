#include <iostream>
#include <array>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = 25;

int n, m, f[(1 << 20) + 5];
std::array<int, M> s[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        s[i] = s[i - 1];
        s[i][x]++;
    }

    std::fill(f + 1, f + (1 << m), std::numeric_limits<int>::max());

    for (int i = 0; i < 1 << m; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) cnt += s[n][j + 1];
        }

        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) continue;

            int l = cnt, r = l + s[n][j + 1];
            f[i | (1 << j)] = std::min(f[i | (1 << j)], f[i] + r - l - (s[r][j + 1] - s[l][j + 1]));
        }
    }

    cout << f[(1 << m) - 1] << endl;

    return 0;
}
