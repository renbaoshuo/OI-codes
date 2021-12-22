#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int t, n, k, ans;
std::string g[55];

void dfs(int x, int y, int cnt, int from) {
    if (x < 0 || x >= n || y < 0 || y > n || cnt > k || g[x][y] == 'H') return;
    if (x == n - 1 && y == n - 1) {
        ans++;
        return;
    }
    dfs(x + 1, y, cnt + (from == 2), 1);
    dfs(x, y + 1, cnt + (from == 1), 2);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        dfs(0, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
