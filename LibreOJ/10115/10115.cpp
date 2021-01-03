#include <bits/stdc++.h>

using namespace std;

int n, m, op, l, r, c1[1000001], c2[1000001];

int lowbit(int x) {
    return x & (-x);
}

inline void update1(int x, int v) {
    while (x <= n) {
        c1[x] += v;
        x += lowbit(x);
    }
}

inline void update2(int x, int v) {
    while (x <= n) {
        c2[x] += v;
        x += lowbit(x);
    }
}

int sum1(int x) {
    int p = 0;
    while (x > 0) {
        p += c1[x];
        x -= lowbit(x);
    }
    return p;
}

int sum2(int x) {
    int p = 0;
    while (x > 0) {
        p += c2[x];
        x -= lowbit(x);
    }
    return p;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> op >> l >> r;
        if (op == 1) {
            update1(l, 1), update2(r, 1);
        }
        if (op == 2) {
            cout << sum1(r) - sum2(l - 1) << endl;
        }
    }
    return 0;
}