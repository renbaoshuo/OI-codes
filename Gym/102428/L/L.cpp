#include <iostream>
#include <stack>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, m, f[N][N], ans;
bool g[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;

            cin >> c;

            g[i][j] = c == 'G';
            f[i][j] = g[i][j] == g[i][j - 1] ? f[i][j - 1] + 1 : 1;
        }
    }

    for (int p = 1; p <= m; p++) {
        std::stack<std::pair<int, int>> st;

        for (int i = 1; i <= n; i++) {
            int l = 0;

            while (!st.empty() && f[st.top().first][p] >= f[i][p]) {
                l += st.top().second;
                ans = std::max(ans, std::min(f[st.top().first][p], l));
                st.pop();
            }

            st.emplace(i, l + 1);
        }

        int l = 0;

        while (!st.empty()) {
            l += st.top().second;
            ans = std::max(ans, std::min(f[st.top().first][p], l));
            st.pop();
        }
    }

    cout << ans * ans << endl;

    return 0;
}
