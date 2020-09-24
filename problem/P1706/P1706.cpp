// R38825486

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    scanf("%d", &n);
    do {
        for (int i = 0; i < n-1; i++) {
            printf("%5d", a[i]);
        }
        printf("%5d\n", a[n-1]);
    } while (next_permutation(a, a + n));
    return 0;
}
