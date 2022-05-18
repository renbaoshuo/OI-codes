#include <algorithm>
#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 10007;

int n, t, c, a[N], st[N], ed[N], add[N], mul[N], pos[N];

inline void update(int x) {
    for (int i = st[x]; i <= ed[x]; i++) {
        a[i] = (a[i] * mul[x] % mod + add[x]) % mod;
    }

    mul[x] = 1;
    add[x] = 0;
}

// 加法
void change1(int l, int r, int c) {
    int p = pos[l],
        q = pos[r];

    if (p == q) {
        update(p);

        for (int i = l; i <= r; i++) {
            a[i] = (a[i] + c) % mod;
        }

        return;
    }

    update(p);
    for (int i = l; i <= ed[p]; i++) a[i] = (a[i] + c) % mod;
    update(q);
    for (int i = st[q]; i <= r; i++) a[i] = (a[i] + c) % mod;
    for (int i = p + 1; i <= q - 1; i++) add[i] = (add[i] + c) % mod;
}

// 乘法
void change2(int l, int r, int c) {
    int p = pos[l],
        q = pos[r];

    if (p == q) {
        update(p);

        for (int i = l; i <= r; i++) {
            a[i] = a[i] * c % mod;
        }

        return;
    }

    update(p);
    for (int i = l; i <= ed[p]; i++) a[i] = a[i] * c % mod;
    update(q);
    for (int i = st[q]; i <= r; i++) a[i] = a[i] * c % mod;
    for (int i = p + 1; i <= q - 1; i++) {
        mul[i] = mul[i] * c % mod;
        add[i] = add[i] * c % mod;
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    std::fill(mul, mul + n + 2, 1);
    t = std::sqrt(n);

    for (c = 1;; c++) {
        st[c] = (c - 1) * t + 1;
        ed[c] = std::min(n, c * t);

        if (c * t >= n) break;
    }

    for (int i = 1; i <= c; i++) {
        for (int j = st[i]; j <= ed[i]; j++) {
            pos[j] = i;
        }
    }

    for (int i = 1, op, l, r, c; i <= n; i++) {
        cin >> op >> l >> r >> c;

        if (op == 0) {
            change1(l, r, c);
        } else if (op == 1) {
            change2(l, r, c);
        } else {  // op == 2
            cout << (a[r] * mul[pos[r]] % mod + add[pos[r]]) % mod << endl;
        }
    }

    return 0;
}
