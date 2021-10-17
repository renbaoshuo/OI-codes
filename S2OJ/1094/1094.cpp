#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int n, a[100005], d[100005], ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
        d[i] = a[i] - a[i - 1];
        if (d[i] > 0) ans += d[i];
    }
    d[0] = INT_MAX;
    d[n + 1] = INT_MIN;
    printf("%d\n", ans);
    for (int i = 1, t = 2; i <= n; i++) {
        while (d[i]) {
            if (d[t] >= 0) {
                t++;
            } else {
                d[i]--;
                d[t]++;
                printf("%d %d\n", i, t - 1);
            }
        }
    }
    return 0;
}
