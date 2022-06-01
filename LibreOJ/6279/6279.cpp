#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, c, t, a[N], b[N], st[N], ed[N], pos[N], add[N];

inline void process(int x) {
    for (int i = st[x]; i <= ed[x]; i++) b[i] = a[i];
    std::sort(b + st[x], b + ed[x] + 1);
}

void change(int l, int r, int c) {
    int p = pos[l], q = pos[r];

    if (p == q) {
        for (int i = l; i <= r; i++) a[i] += c;
        process(p);

        return;
    }

    for (int i = l; i <= ed[p]; i++) a[i] += c;
    process(p);
    for (int i = st[q]; i <= r; i++) a[i] += c;
    process(q);
    for (int i = p + 1; i <= q - 1; i++) add[i] += c;
}

int query(int l, int r, int c) {
    int p = pos[l], q = pos[r];
    int res = std::numeric_limits<int>::min();

    if (p == q) {
        for (int i = l; i <= r; i++) {
            if (a[i] + add[p] < c) res = std::max(res, a[i] + add[p]);
        }
    } else {
        for (int i = l; i <= ed[p]; i++) {
            if (a[i] + add[p] < c) res = std::max(res, a[i] + add[p]);
        }
        for (int i = st[q]; i <= r; i++) {
            if (a[i] + add[q] < c) res = std::max(res, a[i] + add[q]);
        }

        for (int i = p + 1; i <= q - 1; i++) {
            int _ =
                std::lower_bound(b + st[i], b + ed[i] + 1, c - add[i]) - b - 1;

            if (st[i] <= _ && _ <= ed[i]) res = std::max(res, b[_] + add[i]);
        }
    }

    return res == std::numeric_limits<int>::min() ? -1 : res;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    t = std::sqrt(n);

    for (c = 1;; c++) {
        st[c] = (c - 1) * t + 1;
        ed[c] = std::min(n, c * t);
        if (c * t >= n) break;
    }

    for (int i = 1; i <= c; i++) {
        for (int j = st[i]; j <= ed[i]; j++) { pos[j] = i; }
        std::sort(b + st[i], b + ed[i] + 1);
    }

    for (int i = 1, op, l, r, c; i <= n; i++) {
        cin >> op >> l >> r >> c;

        if (op == 0) {
            change(l, r, c);
        } else {  // op == 1
            cout << query(l, r, c) << endl;
        }
    }

    return 0;
}
