#include <bits/stdc++.h>

using namespace std;

int n, m, u[5000005], v[5000005], w[5000005], fa[5000005];
long long ans;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", u + i, v + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", w + i);
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int fu = find(u[i]);
        int fv = find(v[i]);
        fa[fv] = fu;
        w[fu] = max(w[fu], w[fv]);
    }
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i) {
            ans += w[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
