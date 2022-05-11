#pragma GCC optimize("Ofast")

#include <algorithm>
#include <cmath>
#include <cstdio>

const int N = 15;
const double eps = 1e-6;

int n;
double a[N][N], b[N][N];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[i][j] = 2.0 * (a[i][j] - a[i + 1][j]);
            b[i][n + 1] += std::pow(a[i][j], 2) - std::pow(a[i + 1][j], 2);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (std::abs(b[j][i]) > eps) {
                std::swap(b[i], b[j]);
            }
        }

        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            double x = b[j][i] / b[i][i];
            for (int k = i; k <= n + 1; k++) {
                b[j][k] -= b[i][k] * x;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%.3lf ", b[i][n + 1] / b[i][i]);
    }
    printf("\n");

    return 0;
}
