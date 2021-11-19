// R38992526

#include <bits/stdc++.h>

using namespace std;

double a, b, c, d;
int cnt;

double fc(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    for (double i = -100.00; i <= 100.00; i += 0.001) {
        double l = i, r = i + 0.001;
        if (fc(l) * fc(r) < 0) {
            printf("%.2f ", l);
            cnt++;
        }
        if (cnt == 3) {
            printf("\n");
            break;
        }
    }
    return 0;
}
