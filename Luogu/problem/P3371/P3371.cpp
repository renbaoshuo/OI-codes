#include <bits/stdc++.h>

using namespace std;

int n, m, s;
long long u, v, w, f[10005][10005];

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = i == j ? 0 : INT_MAX;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        f[u][v] = min(f[u][v], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == k || f[i][k] == INT_MAX) {
                    continue;
                }
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", f[s][i]);
    }
    printf("\n");
    return 0;
}
