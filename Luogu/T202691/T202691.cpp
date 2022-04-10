#include <cstdio>

const int N = 1e5 + 5;

int t, n, a[N], p[N];

int main() {
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", p + i);
        }

        for (int i = 1; i <= n; i++) {
            if (p[i] == -1) {
                p[i] = p[i - 1] + 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            a[i] = p[i] - p[i - 1];
        }

        for (int i = n; i; i--) {
            if (a[i] > 1000) {
                a[i - 1] += a[i] - 1000;
                a[i] = 1000;
            }
        }

        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
