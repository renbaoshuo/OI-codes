#include <cstdio>

double x;

int main() {
    scanf("%lf", &x);
    printf(
        "%f\n"
        "%.5f\n"
        "%e\n"
        "%g\n",
        x,
        x,
        x,
        x);
    return 0;
}
