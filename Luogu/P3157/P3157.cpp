#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, pos[N];
long long c[N], ans[N];

struct node {
    int t, i, v;

    node() {}

    node(int _t, int _i, int _v)
        : t(_t), i(_i), v(_v) {}

    bool operator<(const node& x) {
        return i == x.i ? v < x.v : i < x.i;
    }
} q[N], w[N];

inline int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (; x <= n; x += lowbit(x)) c[x] += y;
}

int sum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}

void solve(int l, int r) {
    if (l >= r) return;

    int mid = l + r >> 1;

    solve(l, mid);
    solve(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (q[i] < q[j]) {
            add(q[i].v, 1);
            w[++k] = q[i++];
        } else {
            ans[q[j].t] += sum(n) - sum(q[j].v);
            w[++k] = q[j++];
        }
    }

    while (i <= mid) {
        add(q[i].v, 1);
        w[++k] = q[i++];
    }

    while (j <= r) {
        ans[q[j].t] += sum(n) - sum(q[j].v);
        w[++k] = q[j++];
    }

    for (int i = l; i <= mid; i++) add(q[i].v, -1);
    for (int i = l, j = 1; j <= k; i++, j++) q[i] = w[j];

    for (int i = r; i >= l; i--) {
        if (q[i].t <= mid) {
            add(q[i].v, 1);
        } else {
            ans[q[i].t] += sum(q[i].v);
        }
    }

    for (int i = r; i >= l; i--) {
        if (q[i].t <= mid) add(q[i].v, -1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        pos[x] = i;
        q[i] = node(0, i, x);
    }

    int t = n;
    for (int i = 1, x; i <= m; i++) {
        cin >> x;
        q[pos[x]].t = t--;
    }
    for (int i = 1; i <= n; i++) {
        if (!q[i].t) q[i].t = t--;
    }

    std::sort(q + 1, q + 1 + n, [&](const node& a, const node& b) {
        return a.t < b.t;
    });

    solve(1, n);

    for (int i = 1; i <= n; i++) ans[i] += ans[i - 1];

    for (int i = n; i > n - m; i--) {
        cout << ans[i] << endl;
    }

    return 0;
}
