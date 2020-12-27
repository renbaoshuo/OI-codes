#include <bits/stdc++.h>

using namespace std;

inline void read(int& ret) {
    ret = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (isdigit(ch)) {
        ret = ret * 10 + ch - '0', ch = getchar();
    }
    ret *= f;
}

int main() {
    int t;
    read(t);
    while (t--) {
        int n, x;
        unordered_map<int, bool> m;
        read(n);
        for (int i = 0; i < n; i++) {
            read(x);
            if (!m[x]) {
                m[x] = true;
                printf("%d ", x);
            }
        }
        printf("\n");
    }
    return 0;
}
