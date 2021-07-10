#pragma GCC optimize(3)

#include <bits/stdc++.h>

using namespace std;

int n, k, a[10000005];

int main() {
    scanf("%d", &n);
    if (n == 1) {
        printf("None\n");
        exit(0);
    }
    printf("1\n");
    a[k++] = n - 1;
    for (int i = (int)floor(sqrt(n)); 2 * i < n; i++) {
        if (1ull * i * i % n == 1) {
            printf("%d\n", i);
            a[k++] = n - i;
        }
    }
    for (int i = k - 1; i >= 0; i--) {
        printf("%d\n", a[i]);
    }
    return 0;
}
