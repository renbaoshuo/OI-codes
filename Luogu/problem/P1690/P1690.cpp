#include <bits/stdc++.h>

using namespace std;

int n, p, g[105][105], a[15], ans = 0x3f3f3f3f, sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    cin >> p;
    for (int i = 1; i <= p; i++) {
        cin >> a[i];
    }
    a[0] = 1;
    a[p + 1] = n;
    sort(a + 1, a + p + 1);
    do {
        sum = 0;
        for (int i = 0; i <= p; i++) {
            sum += g[a[i]][a[i + 1]];
        }
        ans = min(ans, sum);
    } while (next_permutation(a + 1, a + p + 1));
    cout << ans << endl;
    return 0;
}
