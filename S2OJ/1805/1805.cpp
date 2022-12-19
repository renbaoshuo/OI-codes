#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const long long INF = 0x3f3f3f3f'3f3f3f3f;

struct node {
    long long max;
    node *lchild, *rchild;

    node()
        : max(-INF), lchild(nullptr), rchild(nullptr) {}

    void pushup() {
        max = -INF;

        if (lchild) max = std::max(max, lchild->max);
        if (rchild) max = std::max(max, rchild->max);
    }
};

int k, m, d, a, n, t[N], b[N];
long long f[N];
node *root;

void modify(node *&cur, int l, int r, int x, long long v) {
    if (!cur) cur = new node();

    if (l == r) {
        cur->max = v;

        return;
    }

    int mid = l + r >> 1;

    if (x <= mid) modify(cur->lchild, l, mid, x, v);
    else modify(cur->rchild, mid + 1, r, x, v);

    cur->pushup();
}

long long query(node *cur, int l, int r, int ql, int qr) {
    if (!cur) return -INF;
    if (ql <= l && r <= qr) return cur->max;

    int mid = l + r >> 1;
    long long res = -INF;

    if (ql <= mid) res = std::max(res, query(cur->lchild, l, mid, ql, qr));
    if (qr > mid) res = std::max(res, query(cur->rchild, mid + 1, r, ql, qr));

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> m >> d >> a >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> b[i];
    }

    t[0] = k, t[n + 1] = m;

    modify(root, 0, d - 1, t[0] % d, static_cast<long long>(t[0]) / d * a);

    for (int i = 1; i <= n + 1; i++) {
        f[i] = std::max(
                   query(root, 0, d - 1, 0, (t[i] - 1) % d),
                   query(root, 0, d - 1, (t[i] - 1) % d + 1, d - 1) + a)
             - static_cast<long long>(t[i] - 1) / d * a - a + b[i];
        modify(root, 0, d - 1, t[i] % d, f[i] + static_cast<long long>(t[i]) / d * a);
    }

    cout << f[n + 1] << endl;

    return 0;
}
