// #include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <vector>

// using std::cin;
// using std::cout;
std::ifstream cin("monotony.in");
std::ofstream cout("monotony.out");
const char endl = '\n';

const int R = 15,
          C = 105;
const int mod = 998244353;

int r, c, a[R][C], sum[C][1 << R], f[C][C], ans;
unsigned int op[C][C], st[C][C];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 1; j <= c; j++) {
        for (int k = j + 1; k <= c; k++) {
            for (int i = 1; i <= r; i++) {
                if (a[i][j] < a[i][k]) {
                    op[j][k] |= 1 << (i - 1);
                }
            }
        }
    }

    for (int s = 0; s < (1 << r) - 1; s++) {
        for (int j = 1; j <= c; ++j) {
            for (int k = j + 1; k <= c; ++k) {
                st[j][k] = op[j][k] & (((1 << r) - 1) ^ s);
            }
        }

        std::vector<int> b;

        for (int i = 1; i <= c; i++) {
            std::vector<int> v;

            for (int j = 1; j <= r; j++) {
                if (s & (1 << j - 1)) continue;

                v.emplace_back(a[j][i]);
            }

            if (std::is_sorted(v.begin(), v.end()) || std::is_sorted(v.rbegin(), v.rend())) {
                b.emplace_back(i);
            }
        }

        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < i; j++) {
                int c = st[b[j]][b[i]];
                f[i][j] = (sum[j][c] + 1) % mod;
                sum[i][c] = (static_cast<long long>(sum[i][c]) + f[i][j]) % mod;
                ans = (static_cast<long long>(ans) + f[i][j]) % mod;
            }
        }

        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < i; j++) {
                f[i][j] = 0;
                sum[i][st[b[j]][b[i]]] = 0;
            }
        }

        ans = (static_cast<long long>(ans) + b.size()) % mod;
    }

    cout << ans << endl;

    return 0;
}
