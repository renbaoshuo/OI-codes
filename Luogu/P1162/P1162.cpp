#include <bits/stdc++.h>

using namespace std;

int n, a[32][32], b[32][32];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

void dfs(int x, int y) {
    if (x < 0 || x > n + 1 || y < 0 || y > n + 1 || b[x][y] != 0) {
        return;
    }
    b[x][y] = 2;
    for (int i = 1; i <= 4; i++) {
        dfs(x + dx[i], y + dy[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                b[i][j] = 0;
            } else {
                b[i][j] = 1;
            }
        }
    }
    dfs(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[i][j] == 2) {
                cout << "0 ";
            } else if (b[i][j] == 0) {
                cout << "2 ";
            } else {
                cout << "1 ";
            }
        }
        cout << endl;
    }
    return 0;
}
