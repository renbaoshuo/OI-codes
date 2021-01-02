#include <bits/stdc++.h>

using namespace std;

long long inv[20000005];

int main() {
    inv[0] = 0;
    inv[1] = 1;
    int n, p;
    scanf("%d%d", &n, &p);
    printf("1\n");
    for (int i = 2; i <= n; ++i) {
        inv[i] = (long long)p - (p / i) * inv[p % i] % p;
        printf("%d\n", inv[i]);
    }
    return 0;
}