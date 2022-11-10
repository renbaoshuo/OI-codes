#include <iostream>
#include <array>
#include <bitset>
#include <numeric>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505,
          M = 5005;

int r, c, m, p;
std::string s;
std::array<std::bitset<N>, N> f[M], g;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> m;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char ch;

            cin >> ch;

            g[i].set(j, ch == '.');
        }
    }

    cin >> s;

    f[0] = g;

    for (char op : s) {
        p++;

        if (op == 'N') {
            for (int i = 1; i <= r; i++) {
                f[p][i] = (f[p - 1][i + 1]) & g[i];
            }
        } else if (op == 'E') {
            for (int i = 1; i <= r; i++) {
                f[p][i] = (f[p - 1][i] << 1) & g[i];
            }
        } else if (op == 'S') {
            for (int i = 1; i <= r; i++) {
                f[p][i] = (f[p - 1][i - 1]) & g[i];
            }
        } else if (op == 'W') {
            for (int i = 1; i <= r; i++) {
                f[p][i] = (f[p - 1][i] >> 1) & g[i];
            }
        } else {  // op == '?'
            for (int i = 1; i <= r; i++) {
                f[p][i] = ((f[p - 1][i] >> 1) | (f[p - 1][i] << 1) | f[p - 1][i - 1] | f[p - 1][i + 1]) & g[i];
            }
        }
    }

    cout << std::accumulate(f[m].begin(), f[m].end(), 0, [](int x, auto y) -> int { return x + y.count(); }) << endl;

    return 0;
}
