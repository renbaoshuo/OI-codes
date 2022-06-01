#include <iostream>
#include <cmath>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, c, t, a[N], st[N], ed[N], pos[N], rep[N];

inline void pushdown(int x) {
    if (rep[x] != -1) {
        for (int i = st[x]; i <= ed[x]; i++) a[i] = rep[x];
        rep[x] = -1;
    }
}

int solve(int l, int r, int c) {
    int p = pos[l],
        q = pos[r];
    int res = 0;

    if (p == q) {
        pushdown(p);
        for (int i = l; i <= r; i++) {
            if (a[i] == c) res++;
            a[i] = c;
        }

        return res;
    }

    pushdown(p);
    for (int i = l; i <= ed[p]; i++) {
        if (a[i] == c) res++;
        a[i] = c;
    }

    pushdown(q);
    for (int i = st[q]; i <= r; i++) {
        if (a[i] == c) res++;
        a[i] = c;
    }

    for (int i = p + 1; i <= q - 1; i++) {
        if (rep[i] != -1) {
            if (rep[i] == c) res += ed[i] - st[i] + 1;
        } else {
            for (int j = st[i]; j <= ed[i]; j++) {
                if (a[j] == c) res++;
                a[j] = c;
            }
        }
        rep[i] = c;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    memset(rep, 0xff, sizeof(rep));

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

    for (int i = 1, l, r, c; i <= n; i++) {
        cin >> l >> r >> c;
        cout << solve(l, r, c) << endl;
    }

    return 0;
}
