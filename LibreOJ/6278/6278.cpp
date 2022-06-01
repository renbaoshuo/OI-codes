#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

int n, t, c;
long long a[N], b[N], st[N], ed[N], pos[N], add[N];

void change(int l, int r, int k) {
    int p = pos[l],
        q = pos[r];

    if (p == q) {
        for (int i = l; i <= r; i++) a[i] += k;

        for (int i = st[p]; i <= ed[p]; i++) b[i] = a[i];

        std::sort(b + st[p], b + ed[p] + 1);

        return;
    }

    for (int i = p + 1; i <= q - 1; i++) add[i] += k;

    for (int i = l; i <= ed[p]; i++) a[i] += k;
    for (int i = st[p]; i <= ed[p]; i++) b[i] = a[i];
    std::sort(b + st[p], b + ed[p] + 1);

    for (int i = st[q]; i <= r; i++) a[i] += k;
    for (int i = st[q]; i <= ed[q]; i++) b[i] = a[i];
    std::sort(b + st[q], b + ed[q] + 1);
}

int query(int l, int r, long long k) {
    int p = pos[l],
        q = pos[r];
    int cnt = 0;

    if (p == q) {
        for (int i = l; i <= r; i++) {
            if (a[i] + add[p] < k) cnt++;
        }

        return cnt;
    }

    for (int i = p + 1; i <= q - 1; i++) {
        cnt += std::upper_bound(b + st[i], b + ed[i] + 1, k - add[i] - 1) - b - st[i];
    }

    for (int i = l; i <= ed[p]; i++) {
        if (a[i] + add[p] < k) cnt++;
    }
    for (int i = st[q]; i <= r; i++) {
        if (a[i] + add[q] < k) cnt++;
    }

    return cnt;
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
        for (int j = st[i]; j <= ed[i]; j++) {
            pos[j] = i;
        }
        std::sort(b + st[i], b + ed[i] + 1);
    }

    for (int i = 1, op, l, r, c; i <= n; i++) {
        cin >> op >> l >> r >> c;

        if (op == 0) {
            change(l, r, c);
        } else {  // op == 1
            cout << query(l, r, 1ll * c * c) << endl;
        }
    }

    return 0;
}
