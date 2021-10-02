#include <bits/stdc++.h>

using namespace std;

int n, a[1000005], trie[10000005][2], p = 1, ans;

void insert(int u, int x, int b) {
    if (!x) return;
    if (!trie[u][(x >> b) & 1]) trie[u][(x >> b) & 1] = ++p;
    insert(trie[u][(x >> b) & 1], x - (((x >> b) & 1) << b), b - 1);
}

int search(int u, int x) {
    int res = 0, t = u;
    for (int i = 30; i >= 0; i--) {
        if (!t) break;
        if (trie[t][!((x >> i) & 1)]) {
            res += 1 << i;
            t = trie[t][!((x >> i) & 1)];
        } else {
            t = trie[t][(x >> i) & 1];
        }
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        insert(1, a[i], 30);
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, search(1, a[i]));
    }
    printf("%d\n", ans);
    return 0;
}
