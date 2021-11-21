#include <bits/stdc++.h>

using namespace std;

int n, m;
char g[105][105];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> g[i] + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] != '*') {
                int sum = 0;
                sum += g[i - 1][j - 1] == '*';
                sum += g[i - 1][j] == '*';
                sum += g[i - 1][j + 1] == '*';
                sum += g[i][j - 1] == '*';
                sum += g[i][j + 1] == '*';
                sum += g[i + 1][j - 1] == '*';
                sum += g[i + 1][j] == '*';
                sum += g[i + 1][j + 1] == '*';
                cout << sum;
            } else {
                cout << g[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
