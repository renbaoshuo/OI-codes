#include <bits/stdc++.h>

using namespace std;

int n, m, l, r, k, t, f[100005][25];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i][0]);
    }
    t = log(n) / log(2) + 1;
    for (int i = 1; i < t; i++) {
        for (int j = 1; j <= n - (1 << i) + 1; j++) {
            f[j][i] = max(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &l, &r);
        k = log(r - l + 1) / log(2);
        printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
    }
    return 0;
}
