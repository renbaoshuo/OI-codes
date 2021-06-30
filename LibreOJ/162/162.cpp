#include <bits/stdc++.h>

using namespace std;

const long long m = 998244352;

int read() {
    int x = 0, w = 1;
    char c;
    while (!isdigit(c)) {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * w;
}

long long binpow(long long a, long long b) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    long long x, n, a;
    x = read();
    n = read();
    for (int i = 0; i < n; i++) {
        a = read();
        printf("%lld ", binpow(x, a));
    }
    printf("\n");
    return 0;
}
