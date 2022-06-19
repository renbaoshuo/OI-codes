#include <iostream>
#include <deque>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205;

int n, m, x, y, k, s, t, d, f[N][N], ans;
bool g[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x >> y >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            g[i][j] = c == 'x';
            f[i][j] = -0x3f3f3f3f;
        }
    }

    f[x][y] = 0;
    for (int i = 1; i <= k; i++) {
        cin >> s >> t >> d;

        int len = t - s + 1;
        switch (d) {
            case 1: {  // 上
                for (int y = 1; y <= m; y++) {
                    std::deque<std::pair<int, int>> q;
                    for (int j = 1, x = n; x; j++, x--) {
                        if (g[x][y]) {
                            q.clear();
                        } else {
                            while (!q.empty() && q.back().second < f[x][y] - j) q.pop_back();
                            q.push_back(std::make_pair(j, f[x][y] - j));
                            while (!q.empty() && j - q.front().first > len) q.pop_front();
                            f[x][y] = q.front().second + j;
                            ans = std::max(ans, f[x][y]);
                        }
                    }
                }
                break;
            }
            case 2: {  // 下
                for (int y = 1; y <= m; y++) {
                    std::deque<std::pair<int, int>> q;
                    for (int j = 1, x = 1; x <= n; j++, x++) {
                        if (g[x][y]) {
                            q.clear();
                        } else {
                            while (!q.empty() && q.back().second < f[x][y] - j) q.pop_back();
                            q.push_back(std::make_pair(j, f[x][y] - j));
                            while (!q.empty() && j - q.front().first > len) q.pop_front();
                            f[x][y] = q.front().second + j;
                            ans = std::max(ans, f[x][y]);
                        }
                    }
                }
                break;
            }
            case 3: {  // 左
                for (int x = 1; x <= n; x++) {
                    std::deque<std::pair<int, int>> q;
                    for (int j = 1, y = m; y; j++, y--) {
                        if (g[x][y]) {
                            q.clear();
                        } else {
                            while (!q.empty() && q.back().second < f[x][y] - j) q.pop_back();
                            q.push_back(std::make_pair(j, f[x][y] - j));
                            while (!q.empty() && j - q.front().first > len) q.pop_front();
                            f[x][y] = q.front().second + j;
                            ans = std::max(ans, f[x][y]);
                        }
                    }
                }
                break;
            }
            case 4: {  // 右
                for (int x = 1; x <= n; x++) {
                    std::deque<std::pair<int, int>> q;
                    for (int j = 1, y = 1; y <= m; j++, y++) {
                        if (g[x][y]) {
                            q.clear();
                        } else {
                            while (!q.empty() && q.back().second < f[x][y] - j) q.pop_back();
                            q.push_back(std::make_pair(j, f[x][y] - j));
                            while (!q.empty() && j - q.front().first > len) q.pop_front();
                            f[x][y] = q.front().second + j;
                            ans = std::max(ans, f[x][y]);
                        }
                    }
                }
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
