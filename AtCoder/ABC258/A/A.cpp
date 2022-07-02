#include <cstdio>

int main() {
    int k;

    scanf("%d", &k);

    printf("%02d:%02d\n", k >= 60 ? 22 : 21, k % 60);

    return 0;
}
