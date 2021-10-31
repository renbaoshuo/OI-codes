#include <bits/stdc++.h>

using namespace std;

int p, f, c, a[505][505], b[8005], u, v, g, ans, sum = 0x3f3f3f3f, cnt;

int main() {
    cin >> p >> f >> c;
    memset(a, 0x3f, sizeof(a));
    for (int i = 1; i <= p; i++) {
        a[i][i] = 0;
    }
    for (int i = 1; i <= f; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= c; i++) {
        cin >> u >> v >> g;
        a[u][v] = g;
        a[v][u] = g;
    }
    for (int k = 1; k <= p; k++) {
        for (int i = 1; i <= p; i++) {
            for (int j = 1; j <= p; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    for (int i = 1; i <= p; i++) {
        cnt = 0;
        for (int j = 1; j <= f; j++) {
            cnt += a[i][b[j]];
        }
        if (cnt < sum) {
            ans = i;
            sum = cnt;
        }
    }
    cout << ans << endl;
    return 0;
}
