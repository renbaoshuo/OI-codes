#include <bits/stdc++.h>

using namespace std;

int n;

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

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 ^ 48);
    return;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        write(i);
        putchar(' ');
    }
    putchar('\n');
    return 0;
}
