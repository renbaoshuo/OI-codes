#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include "testlib.h"
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
inline void Mx(T& x, T y) {
    x < y && (x = y);
}

template <typename T>
inline void Mn(T& x, T y) {
    x > y && (x = y);
}

const int N = 205000;
int a[N], d[N];
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();
    for (int i = 1; i <= n; ++i)
        a[i] = inf.readInt();
    int m = ans.readInt(1, 100000);
    int t = ouf.readInt(1, 100000);
    if (t > m) {
        quitf(_wa, "your m is larger");
        return 0;
    }
    if (t < m) {
        quitf(_wa, "your m is smaller");
        return 0;
    }
    for (int i = 1; i <= m; ++i) {
        int l = ouf.readInt(1, n), r = ouf.readInt(l, n);
        d[l]++, d[r + 1]--;
    }
    int nw = 0;
    for (int i = 1; i <= n; ++i) {
        nw += d[i], a[i] -= nw;
        if (a[i])
            quitf(_wa, "your ans is not correct");
    }
    quitf(_ok, "Correct");
    return 0;
}
