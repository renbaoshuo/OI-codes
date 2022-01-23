#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n, a[20][20], ans;
bool vis[20];

void dfs(int pos, int val) {
    while (vis[pos]) pos++;
    if (pos == n + 1) {
        ans = std::max(ans, val);
        return;
    }
    for (int i = pos + 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        dfs(pos + 1, val ^ a[i][pos]);
        vis[i] = false;
    }
}

int main() {
    cin >> n;
    n <<= 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
