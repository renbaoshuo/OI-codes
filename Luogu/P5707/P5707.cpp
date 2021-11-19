#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, v, m, h;
    scanf("%d%d", &s, &v);
    m = s / v;
    if (s % v != 0) {
        m++;
    }
    m += 10;
    h = m / 60;
    m %= 60;
    if (h > 7) {
        printf("%02d", 24 + 7 - h);
    } else {
        printf("%02d", 7 - h);
    }
    printf(":%02d\n", 60 - m);
    return 0;
}
