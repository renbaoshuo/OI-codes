#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5005;

int n, m, c[N], st[N], mx[N], ans[N << 1];
bool g[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;

            cin >> c;

            g[i][j] = c == '#';
        }
    }

    for (int i = 1; i <= n; i++) {
        int top = 0;
        st[0] = 0;
        mx[0] = std::numeric_limits<int>::min();

        for (int j = 1; j <= m; j++) {
            if (g[i][j]) c[j] = 0;
            else c[j]++;
        }

        for (int j = 1; j <= m; j++) {
            while (top && c[st[top]] >= c[j]) top--;

            if (c[j] == 0) {
                st[0] = j;
            } else {
                st[++top] = j;
                mx[top] = std::max(mx[top - 1], c[st[top]] - st[top - 1]);

                if (!g[i][j]) ans[j + mx[top]]++;
            }
        }
    }

    for (int i = 1; i <= n + m; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
