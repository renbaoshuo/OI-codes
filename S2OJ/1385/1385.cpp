#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

void solve() {
    std::vector<int> st(3), ed(3);
    std::string s;

    for (int i = 0; i < 3; i++) {
        std::string t;

        cin >> t;

        st[i] = s.size();
        s += t;
        ed[i] = s.size() - 1;
    }

    std::function<int(int)> id = [&](int x) -> int {
        return std::distance(std::begin(ed), std::lower_bound(std::begin(ed), std::end(ed), x));
    };

    int n = s.size();
    std::vector<std::vector<long long>>
        f(n, std::vector<long long>(n)),
        g(3, std::vector<long long>(n)),
        h(3, std::vector<long long>(n));
    long long w = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (s[i] != s[j]) continue;

            int id_i = id(i),
                id_j = id(j);

            if (id_i == 0 && id_j == 2) {
                f[i][j] = 1;
            }

            f[i][j] += g[id_j][i];  // 加上右边块的贡献
            f[i][j] += h[id_i][j];  // 加上左边块的贡献

            if (id_i == 1 && id_j == 1) {
                f[i][j] += w;  // 加上两边来的贡献
            }

            if (i != st[id_i] && j != ed[id_j]) {
                f[i][j] += f[i - 1][j + 1];  // 还在块内，不跳到下一块
            }

            if (id_i == 0 && id_j == 2) {
                w += f[i][j];  // 如果在两边的块，更新贡献
            }

            if (id_j != 0 && i != ed[id_i]) {
                g[id_j - 1][i + 1] += f[i][j];  // 更新到左边块的贡献
            }

            if (id_i != 2 && j != st[id_j]) {
                h[id_i + 1][j - 1] += f[i][j];  // 更新到右边块的贡献
            }

            if (id_i == id_j) {
                if (j - i + 1 <= 3) {
                    // j - i + 1 == 2: i, j 相邻，总长度为偶数
                    //           == 3: i, j 之间还有一个字符，总长度为奇数
                    ans += f[i][j];
                }
            } else if (id_i + 1 == id_j) {  // i 和 j 在相邻块中
                ans += static_cast<long long>(
                           1                  // i, j 之间不拼字符，总长度为偶数
                           + (i != ed[id_i])  // 如果 i 不是块末尾，还可以在中间拼一个字符，总长度为奇数
                           + (j != st[id_j])  // 如果 j 不是块开头，还可以在中间拼一个字符，总长度为奇数
                           )
                     * f[i][j];
            }
        }
    }

    ans += w * (ed[1] - st[1] + 1);

    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) solve();

    return 0;
}
