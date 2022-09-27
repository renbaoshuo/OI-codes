#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 35005,
          K = 55;

template <typename T>
class SegmentTree {
  private:
    struct node {
        int l, r;
        T m, d;
        node *lchild, *rchild;

        node(int _l = 0, int _r = 0)
            : l(_l),
              r(_r),
              m(0),
              d(0),
              lchild(nullptr),
              rchild(nullptr) {}

        ~node() {
            delete lchild;
            delete rchild;
        }

        void pushup() {
            m = 0;
            if (lchild) m = std::max(m, lchild->m);
            if (rchild) m = std::max(m, rchild->m);
        }

        void pushdown() {
            if (!d) return;

            lchild->d += d;
            rchild->d += d;

            lchild->m += d;
            rchild->m += d;

            d = 0;
        }
    };

    void build(node *&u, int l, int r) {
        u = new node(l, r);

        if (l == r) return;

        int mid = l + r >> 1;
        build(u->lchild, l, mid);
        build(u->rchild, mid + 1, r);
    }

    void modify(node *u, int l, int r, T v) {
        if (l <= u->l && u->r <= r) {
            u->d += v;
            u->m += v;

            return;
        }

        u->pushdown();

        int mid = u->l + u->r >> 1;
        if (l <= mid) modify(u->lchild, l, r, v);
        if (r > mid) modify(u->rchild, l, r, v);

        u->pushup();
    }

    T query(node *u, int l, int r) {
        if (l <= u->l && u->r <= r) return u->m;

        u->pushdown();

        int mid = u->l + u->r >> 1;
        T res = 0;
        if (l <= mid) res = std::max(res, query(u->lchild, l, r));
        if (r > mid) res = std::max(res, query(u->rchild, l, r));

        return res;
    }

    node *root;

  public:
    SegmentTree(int n)
        : root(nullptr) {
        build(root, 1, n);
    }

    void modify(int l, int r, T v) {
        modify(root, l, r, v);
    }

    T query(int l, int r) {
        return query(root, l, r);
    }
};

int n, k, a[N], pre[N], pos[N], f[K][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        pre[i] = pos[a[i]];
        pos[a[i]] = i;
    }

    for (int i = 1; i <= k; i++) {
        SegmentTree<int> tr(n);

        for (int j = 1; j <= n; j++) {
            tr.modify(j, j, f[i - 1][j - 1]);
        }

        for (int j = 1; j <= n; j++) {
            tr.modify(pre[j] + 1, j, 1);
            f[i][j] = tr.query(i, j);
        }
    }

    cout << f[k][n] << endl;

    return 0;
}
