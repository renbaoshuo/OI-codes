#include <bits/stdc++.h>

using namespace std;

int main() {
    double s, a, b;
    scanf("%lf%lf%lf", &s, &a, &b);
    printf("%.6lf\n", ((b + a) * s / (b + 3 * a)) / b + (s - ((b + a) * s / (b + 3 * a))) / a);
    return 0;
}
