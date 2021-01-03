#include <bits/stdc++.h>

using namespace std;

long long l, n, t;
char s[55];

int main() {
    scanf("%s%lld", s + 1, &n);
    l = t = strlen(s + 1);
    while (t < n) {
        t <<= 1;
    }
    while (t != l) {
        t >>= 1;
        n = n > t ? ((t + 1 != n) ? n - 1 - t : t) : n;
    }
    printf("%c\n", s[n]);
    return 0;
}