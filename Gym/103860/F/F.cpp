#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 22;

int n;
long long a[N], x, ans;
bool vis[N];

void dfs(int idx, long long now, int cnt) {
    if (now < ans) return;
    if (cnt == n || now < a[1]) {
        ans = std::max(ans, now);

        return;
    }

    vis[idx] = true;

    for (int i = 1; i <= n; i++) {
        if (now < a[i]) break;
        if (vis[i]) continue;

        dfs(i, now % a[i], cnt + 1);
    }

    vis[idx] = false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> x;

    std::sort(a + 1, a + 1 + n);

    dfs(0, x, 0);

    cout << ans << endl;

    return 0;
}
