#include <cstdio>

int main() {
    int a, b, c;
    scanf("%1d%1d%1d", &a, &b, &c);
    printf("%d\n", (a * 100 + b * 10 + c) + (b * 100 + c * 10 + a) + (c * 100 + a * 10 + b));
    return 0;
}
