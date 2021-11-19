#include <bits/stdc++.h>

using namespace std;

int n;
bool col[20], dg[20], udg[20];
char g[20][20];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            cout << g[i] << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
