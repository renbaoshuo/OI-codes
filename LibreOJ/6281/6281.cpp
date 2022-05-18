#include <algorithm>
#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 50005;

int n, t, c, a[N], st[N], ed[N], pos[N], sum[N];
bool done[N];

void change(int l, int r) {
    int p = pos[l],
        q = pos[r];

    if (p == q) {
        for (int i = l; i <= r; i++) {
            sum[p] -= a[i];
            a[i] = std::sqrt(a[i]);
            sum[p] += a[i];
        }

        return;
    }

    for (int i = l; i <= ed[p]; i++) {
        sum[p] -= a[i];
        a[i] = std::floor(std::sqrt(a[i]));
        sum[p] += a[i];
    }

    for (int i = st[q]; i <= r; i++) {
        sum[q] -= a[i];
        a[i] = std::floor(std::sqrt(a[i]));
        sum[q] += a[i];
    }

    for (int i = p + 1; i <= q - 1; i++) {
        if (done[i]) continue;

        bool flag = true;

        for (int j = st[i]; j <= ed[i]; j++) {
            sum[i] -= a[j];
            flag &= (a[j] = std::floor(std::sqrt(a[j]))) == 1;
            sum[i] += a[j];
        }

        if (flag) done[i] = true;
    }
}

int query(int l, int r) {
    int p = pos[l],
        q = pos[r];
    int res = 0;

    if (p == q) {
        if (done[p]) return r - l + 1;

        for (int i = l; i <= r; i++) {
            res += a[i];
        }

        return res;
    }

    for (int i = l; i <= ed[p]; i++) {
        res += a[i];
    }
    for (int i = st[q]; i <= r; i++) {
        res += a[i];
    }

    for (int i = p + 1; i <= q - 1; i++) {
        if (done[i]) {
            res += ed[i] - st[i] + 1;
        } else {
            for (int j = st[i]; j <= ed[i]; j++) {
                res += a[j];
            }
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
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
    }

    for (int i = 1, op, l, r, c; i <= n; i++) {
        cin >> op >> l >> r >> c;

        if (op == 0) {
            change(l, r);
        } else {  // op == 1
            cout << query(l, r) << endl;
        }
    }

    return 0;
}
