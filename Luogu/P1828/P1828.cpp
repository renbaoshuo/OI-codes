#include <bits/stdc++.h>

using namespace std;

int n, p, c, x, a, b, d, cnt[805], g[805][805], sum, ans = 0x3f3f3f3f;

int main() {
    cin >> n >> p >> c;
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p; j++) {
            g[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= c; i++) {
        cin >> a >> b >> d;
        g[a][b] = d;
        g[b][a] = d;
    }
    for (int k = 1; k <= p; k++) {
        for (int i = 1; i <= p; i++) {
            for (int j = 1; j <= i; j++) {
                g[j][i] = g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 1; i <= p; i++) {
        sum = 0;
        for (int j = 1; j <= p; j++) {
            sum += g[i][j] * cnt[j];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
