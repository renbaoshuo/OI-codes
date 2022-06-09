#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          K = 2e5 + 5;

int n, k, ans[K];
int c[K];

struct node {
    int a, b, c, cnt, res;

    node()
        : a(0), b(0), c(0), cnt(0), res(0) {}

    node(int _a, int _b, int _c)
        : a(_a), b(_b), c(_c), cnt(1), res(0) {}

    bool operator<(const node& x) const {
        return a == x.a ? b == x.b ? c < x.c : b < x.b : a < x.a;
    }

    bool operator==(const node& x) const {
        return a == x.a && b == x.b && c == x.c;
    }
} q[N], w[N];

inline int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (; x <= 2e5; x += lowbit(x)) c[x] += y;
}

int sum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}

void merge_sort(int l, int r) {
    if (l >= r) return;

    int mid = l + r >> 1;

    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        if (q[i].b <= q[j].b) {
            add(q[i].c, q[i].cnt);
            w[++k] = q[i++];
        } else {
            q[j].res += sum(q[j].c);
            w[++k] = q[j++];
        }
    }

    while (i <= mid) {
        add(q[i].c, q[i].cnt);
        w[++k] = q[i++];
    }

    while (j <= r) {
        q[j].res += sum(q[j].c);
        w[++k] = q[j++];
    }

    for (int i = l; i <= mid; i++) add(q[i].c, -q[i].cnt);
    for (int i = l, j = 1; j <= k; i++, j++) q[i] = w[j];
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 1, a, b, c; i <= n; i++) {
        cin >> a >> b >> c;

        q[i] = node(a, b, c);
    }

    std::sort(q + 1, q + 1 + n);

    int k = 1;
    for (int i = 2; i <= n; i++) {
        if (q[i] == q[k]) {
            q[k].cnt++;
        } else {
            q[++k] = q[i];
        }
    }

    merge_sort(1, k);

    for (int i = 1; i <= k; i++) {
        ans[q[i].res + q[i].cnt - 1] += q[i].cnt;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
