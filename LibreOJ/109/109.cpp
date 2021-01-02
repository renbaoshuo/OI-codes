#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int n, m, op, u, v, fa[4000005];
long long ans;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &op, &u, &v);
        if (op == 0) {
            merge(u, v);
        } else {
            ans <<= 1ll, ans |= 1ll * (find(u) == find(v));
        }
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}