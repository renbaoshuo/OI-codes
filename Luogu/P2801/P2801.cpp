#include <algorithm>
#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, q, t, c, a[N], b[N], st[N], ed[N], pos[N], add[N];

inline void process(int x) {
    for (int i = st[x]; i <= ed[x]; i++) b[i] = a[i];
    std::sort(b + st[x], b + ed[x] + 1);
}

void change(int l, int r, int c) {
    int p = pos[l],
        q = pos[r];

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
    int p = pos[l],
        q = pos[r];
    int cnt = 0;

    if (p == q) {
        for (int i = l; i <= r; i++) {
            if (a[i] + add[p] < c) cnt++;
        }

        return cnt;
    }

    for (int i = l; i <= ed[p]; i++) {
        if (a[i] + add[p] < c) cnt++;
    }
    for (int i = st[q]; i <= r; i++) {
        if (a[i] + add[q] < c) cnt++;
    }
    for (int i = p + 1; i <= q - 1; i++) {
        cnt += std::lower_bound(b + st[i], b + ed[i] + 1, c - add[i]) - b - st[i];
    }

    return cnt;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> q;

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
        for (int j = st[i]; j <= ed[i]; j++) {
            pos[j] = i;
        }
        std::sort(b + st[i], b + ed[i] + 1);
    }

    while (q--) {
        char op;
        int l, r, w;
        cin >> op >> l >> r >> w;

        if (op == 'M') {
            change(l, r, w);
        } else {  // op == 'A'
            cout << r - l + 1 - query(l, r, w) << endl;
        }
    }

    return 0;
}
