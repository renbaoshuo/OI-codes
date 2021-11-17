#include <bits/stdc++.h>

using namespace std;

int n, ans, a[105];
bool col[105], dg[105], udg[105];

void dfs(int i) {
    if (i > n) {
        if (ans < 3) {
            for (int i = 1; i < n; i++) {
                cout << a[i] << ' ';
            }
            cout << a[n] << endl;
        }
        ans++;
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (!col[j] && !dg[i + j] && !udg[n - j + i]) {
            a[i] = j;
            col[j] = dg[i + j] = udg[n - j + i] = true;
            dfs(i + 1);
            col[j] = dg[i + j] = udg[n - j + i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}
