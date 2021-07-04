#include <bits/stdc++.h>

using namespace std;

int l, r, ans, m, s[5], a[25][5];

void dfs(int x, int y) {
    if (x > s[y]) {
        m = min(m, max(l, r));
        return;
    }
    l += a[x][y];
    dfs(x + 1, y);
    l -= a[x][y];
    r += a[x][y];
    dfs(x + 1, y);
    r -= a[x][y];
}

int main() {
    cin >> s[1] >> s[2] >> s[3] >> s[4];
    for (int i = 1; i <= 4; i++) {
        l = r = 0;
        m = 0x3f3f3f3f;
        for (int j = 1; j <= s[i]; j++) {
            cin >> a[j][i];
        }
        dfs(1, i);
        ans += m;
    }
    cout << ans << endl;
    return 0;
}
