#include <iostream>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 55;

int n, m, k;
char g[N][N];
std::vector<std::pair<int, int>> points[2];

void dfs(int x, int y, std::vector<std::pair<int, int>> &ps) {
    if (x < 1 || x > n || y < 1 || y > m) return;
    if (g[x][y] == '.') return;
    g[x][y] = '.';
    ps.push_back(std::make_pair(x, y));
    dfs(x + 1, y, ps);
    dfs(x - 1, y, ps);
    dfs(x, y + 1, ps);
    dfs(x, y - 1, ps);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> g[i] + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'X') {
                dfs(i, j, points[k++]);
            }
        }
    }
    int ans = std::numeric_limits<int>::max();
    for (auto a : points[0]) {
        for (auto b : points[1]) {
            ans = std::min(ans, std::abs(a.first - b.first) + std::abs(a.second - b.second) - 1);
        }
    }
    cout << ans << endl;
    return 0;
}
