#include <bits/stdc++.h>

using namespace std;

int t;
long long n, p, f, ans;

int main() {
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        f = 1;
        scanf("%lld%lld", &n, &p);
        if (p == 1) {
            printf("0\n");
            continue;
        }
        for (long long k = n; k; k /= p) {
            ans += f * k;
            f = -f;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
