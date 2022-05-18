#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 50005;

int n, t, c, a[N], st[N], ed[N], pos[N];
long long sum[N], add[N];

void change(int l, int r, int c) {
    int p = pos[l],
        q = pos[r];

    if (p == q) {
        for (int i = l; i <= r; i++) {
            a[i] += c;
        }
        sum[p] += (r - l + 1) * c;

        return;
    }

    for (int i = l; i <= ed[p]; i++) a[i] += c;
    sum[p] += (ed[p] - l + 1) * c;

    for (int i = st[q]; i <= r; i++) a[i] += c;
    sum[q] += (r - st[q] + 1) * c;

    for (int i = p + 1; i <= q - 1; i++) add[i] += c;
}

int query(int l, int r, int c) {
    int p = pos[l],
        q = pos[r];
    int res = 0;

    if (p == q) {
        for (int i = l; i <= r; i++) {
            res = (res + a[i] + add[p]) % (c + 1);
        }

        return res;
    }

    for (int i = l; i <= ed[p]; i++) res = (res + a[i] + add[p]) % (c + 1);
    for (int i = st[q]; i <= r; i++) res = (res + a[i] + add[q]) % (c + 1);

    for (int i = p + 1; i <= q - 1; i++) res = (res + sum[i] + 1ll * add[i] * t) % (c + 1);

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
        ed[c] = std::min(n, t * c);

        if (t * c >= n) break;
    }

    for (int i = 1; i <= c; i++) {
        for (int j = st[i]; j <= ed[i]; j++) {
            pos[j] = i;
            sum[i] += a[j];
        }
    }

    for (int i = 1, op, l, r, c; i <= n; i++) {
        cin >> op >> l >> r >> c;

        if (op == 0) {
            change(l, r, c);
        } else {  // op == 1
            cout << query(l, r, c) % (c + 1) << endl;
        }
    }

    return 0;
}
