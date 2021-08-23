#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int n, l, r, cntl, cntr;
char op;
long long x, c1[300005], c2[300005];

inline int lowbit(int x) {
    return x & -x;
}

inline void add1(int pos, long long x) {
    while (pos <= n) {
        c1[pos] += x;
        pos += lowbit(pos);
    }
}

inline void add2(int pos, long long x) {
    while (pos <= n) {
        c2[pos] += x;
        pos += lowbit(pos);
    }
}

inline long long query1(int pos) {
    long long ret = 0;
    while (pos) {
        ret += c1[pos];
        pos -= lowbit(pos);
    }
    return ret;
}

inline long long query2(int pos) {
    long long ret = 0;
    while (pos) {
        ret += c2[pos];
        pos -= lowbit(pos);
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == 'I') {
            cin >> x;
            add1(++cntl, x);
        } else if (op == 'D') {
            x = query1(cntl) - query1(cntl - 1);
            add1(cntl--, -x);
        } else if (op == 'L') {
            if (cntl > 0) {
                x = query1(cntl) - query1(cntl - 1);
                add1(cntl--, -x);
                add2(++cntr, x);
            }
        } else if (op == 'R') {
            if (cntr > 0) {
                x = query2(cntr) - query2(cntr - 1);
                add2(cntr--, -x);
                add1(++cntl, x);
            }
        } else if (op == 'Q') {
            cin >> l >> r;
            if (r <= cntl) {
                cout << query1(r) - query1(l - 1) << endl;
            } else if (l > cntl) {
                cout << query2(cntl + cntr - l + 1) - query2(cntl + cntr - r) << endl;
            } else {
                cout << query1(cntl) - query1(l - 1) + query2(cntr) - query2(cntl + cntr - r) << endl;
            }
        } else if (op == 'C') {
            cin >> l >> x;
            if (l <= cntl) {
                r = query1(l) - query1(l - 1);
                add1(l, x - r);
            } else {
                r = query2(cntl + cntr - l + 1) - query2(cntl + cntr - l);
                add2(cntl + cntr - l + 1, x - r);
            }
        }
    }
    return 0;
}
