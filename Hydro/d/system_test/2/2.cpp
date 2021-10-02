#include <bits/stdc++.h>

using namespace std;

int n, x;

inline int read() {
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

int main() {
    n = read();
    for (int i = 0; i <= n; i++) {
        x = read();
    }
    printf("%d\n", x);
    return 0;
}
