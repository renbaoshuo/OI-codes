// R39032040

#include <bits/stdc++.h>

using namespace std;

int  n, m;
int  num[105];
bool vis[105];

void dfs(int k) {
    if (k == n + 1) {
        for (int j = 1; j <= n; j++) {
            cout << setw(3) << num[j];
        }
        cout << endl;
        return;
    }
    for (int i = num[k - 1]; i <= m; i++) {
        if (!vis[i]) {
            num[k] = i;
            vis[i] = true;
            dfs(k + 1);
            vis[i] = false;
        }
    }
}

int main() {
    cin >> m >> n;
    num[0] = 1;
    dfs(1);
    return 0;
}
