#include <stdio.h>

int n, p, a, ans;

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        ans += a < p;
    }
    printf("%d\n", ans);
    return 0;
}
