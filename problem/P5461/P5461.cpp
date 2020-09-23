// R38778619

#include <bits/stdc++.h>

using namespace std;

int n, p = 1, a[1050][1050];

void dfs(int x, int l, int q) {
    if (x == 2) {
        a[l][q] = 0;
        return;
    }
    for (int i = l; i <= l + x / 2 - 1; i++) {
        for (int j = q; j <= q + x / 2 - 1; j++) {
            a[i][j] = 0;
        }
    }
    dfs(x / 2, l + x / 2, q);
    dfs(x / 2, l + x / 2, q + x / 2);
    dfs(x / 2, l, q + x / 2);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p *= 2;
    }
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p; j++) {
            a[i][j] = 1;
        }
    }
    dfs(p, 1, 1);
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p - 1; j++) {
            cout << a[i][j] << " ";
        }
        cout << a[i][p] << endl;
    }
    return 0;
}
