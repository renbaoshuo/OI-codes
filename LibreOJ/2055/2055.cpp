#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

template <typename T>
class SegmentTree {
  private:
    struct node {
        int l, r;
        T sum, tag;
        node *lchild, *rchild;

        node(const int &_l = 0, const int &_r = 0)
            : l(_l), r(_r), sum(0), tag(-1), lchild(nullptr), rchild(nullptr) {}

        ~node() {
            if (lchild) delete lchild;
            if (rchild) delete rchild;
        }

        void pushup() {
            sum = 0;

            if (lchild != nullptr) sum += lchild->sum;
            if (rchild != nullptr) sum += rchild->sum;
        }

        void pushdown() {
            if (tag == -1) return;

            int mid = (l + r) >> 1;

            if (lchild == nullptr) lchild = new node(l, mid);
            if (rchild == nullptr) rchild = new node(mid + 1, r);

            lchild->sum = static_cast<T>(lchild->r - lchild->l + 1) * tag;
            lchild->tag = tag;

            rchild->sum = static_cast<T>(rchild->r - rchild->l + 1) * tag;
            rchild->tag = tag;

            tag = -1;
        }
    };

    const int n;
    node *root;

    void modify(node *&cur, int l, int r, int ql, int qr, T val) {
        if (cur == nullptr) cur = new node(l, r);

        if (ql <= l && r <= qr) {
            cur->sum = static_cast<T>(r - l + 1) * val;
            cur->tag = val;

            return;
        }

        int mid = (l + r) >> 1;

        cur->pushdown();

        if (ql <= mid) modify(cur->lchild, l, mid, ql, qr, val);
        if (qr > mid) modify(cur->rchild, mid + 1, r, ql, qr, val);

        cur->pushup();
    }

    T query(node *cur, int l, int r, int ql, int qr) {
        if (cur == nullptr) return T();
        if (ql <= l && r <= qr) return cur->sum;

        int mid = (l + r) >> 1;
        T res = 0;

        cur->pushdown();

        if (ql <= mid) res += query(cur->lchild, l, mid, ql, qr);
        if (qr > mid) res += query(cur->rchild, mid + 1, r, ql, qr);

        return res;
    }

  public:
    SegmentTree(const int &_n)
        : n(_n), root(nullptr) {}

    SegmentTree(const std::vector<T> &vec)
        : n(vec.size()), root(nullptr) {
        std::function<void(node *&, int, int)> build = [&](node *&cur, int l, int r) {
            cur = new node(l, r);

            if (l == r) {
                cur->sum = vec[l - 1];

                return;
            }

            int mid = (l + r) >> 1;

            build(cur->lchild, l, mid);
            build(cur->rchild, mid + 1, r);

            cur->pushup();
        };

        build(root, 1, n);
    }

    ~SegmentTree() {
        if (root) delete root;
    }

    void modify(int ql, int qr, T val) {
        if (ql > qr) return;

        modify(root, 1, n, ql, qr, val);
    }

    T query(int ql, int qr) {
        if (ql > qr) return T();

        return query(root, 1, n, ql, qr);
    }
};

int n, m, q, a[N];
std::tuple<int, int, int> qs[N];

bool check(int x) {
    std::vector<int> vec;

    std::transform(a + 1, a + 1 + n, std::back_inserter(vec), std::bind(std::greater_equal<>(), std::placeholders::_1, x));

    SegmentTree<int> tr(vec);

    for (int i = 1; i <= m; i++) {
        int op, l, r;

        std::tie(op, l, r) = qs[i];

        int cnt = tr.query(l, r);

        if (op == 0) {
            tr.modify(r - cnt + 1, r, 1);
            tr.modify(l, r - cnt, 0);
        } else {  // op == 1
            tr.modify(l, l + cnt - 1, 1);
            tr.modify(l + cnt, r, 0);
        }
    }

    return tr.query(q, q) == 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> std::get<0>(qs[i]) >> std::get<1>(qs[i]) >> std::get<2>(qs[i]);
    }

    cin >> q;

    int l = 1,
        r = n,
        res = 0;

    while (l <= r) {
        int mid = l + r >> 1;

        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << res << endl;

    return 0;
}
