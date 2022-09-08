#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55;

int n, m, t, f[N][N][2], g[2505];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
        int last = 0;
        std::string s;
        std::vector<std::pair<int, int>> blocks;

        cin >> s;

        for (int j = 0; j < m; j++) {
            if (s[j] != s[last]) {
                blocks.emplace_back(last + 1, j);
                last = j;
            }
        }

        if (last != m) {
            blocks.emplace_back(last + 1, m);
        }

        for (int i = 1; i <= blocks.size(); i++) {
            const auto &block = blocks[i - 1];

            for (int j = blocks.size(); j; j--) {
                // 不染色时直接从前一格转移
                f[i][j][0] = std::max(f[i - 1][j][0], f[i - 1][j][1]);

                // 刷成和上个格子一样的颜色
                f[i][j][1] = std::max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + block.second - block.first + 1;

                // 刷成和上上个格子一样的颜色
                if (i >= 2) {
                    f[i][j][1] = std::max(f[i][j][1], f[i - 2][j][1] + block.second - block.first + 1);
                }
            }
        }

        for (int j = t; j >= 0; j--) {
            for (int k = 0; k <= std::min(j, static_cast<int>(blocks.size())); k++) {
                g[j] = std::max(g[j], g[j - k] + std::max(f[blocks.size()][k][0], f[blocks.size()][k][1]));
            }
        }
    }

    cout << g[t] << endl;

    return 0;
}
