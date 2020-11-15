#include <bits/stdc++.h>

using namespace std;

int n, ans, a[200], b[200], dg[200], udg[200];

void dfs(int i) {
    if (i > n) {
        if (ans < 3) {
            for (int j = 1; j <= n; j++) {
                cout << a[j] << ' ';
            }
            cout << endl;
        }
        ans++;
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (!b[j] && !dg[i + j] && !udg[n - j + i]) {
            a[i] = j;
            b[j] = dg[i + j] = udg[n - j + i] = true;
            dfs(i + 1);
            b[j] = dg[i + j] = udg[n - j + i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}
