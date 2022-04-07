#include <cstdio>

const int N = 105,
          M = 1e6 + 5;

int n, m, v[N], s[N], g[M];
bool f[M];

int main() {
    while (scanf("%d%d", &n, &m), n || m) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", v + i);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", s + i);
        }

        for (int i = 1; i <= m; i++) f[i] = 0;
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) g[j] = 0;
            for (int j = v[i]; j <= m; j++) {
                if (!f[j] && f[j - v[i]] && g[j - v[i]] < s[i]) {
                    f[j] = true;
                    g[j] = g[j - v[i]] + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= m; i++) ans += f[i];
        printf("%d\n", ans);
    }

    return 0;
}
