#include <iostream>
#include <chrono>
#include <limits>
#include <random>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5;

class Treap {
  private:
    struct node {
        node *lchild, *rchild;
        int size, value, key;

        node()
            : lchild(nullptr), rchild(nullptr), size(0), value(0), key(rand()) {}

        node(int _value)
            : lchild(nullptr), rchild(nullptr), size(1), value(_value), key(rand()) {}

        ~node() {
            delete lchild;
            delete rchild;
        }

        inline void pushup() {
            size = 1;
            if (lchild != nullptr) size += lchild->size;
            if (rchild != nullptr) size += rchild->size;
        }
    } * root;

    inline int getNodeSize(node *node) {
        return node == nullptr ? 0 : node->size;
    }

    std::pair<node *, node *> split(node *p, int k) {
        if (p == nullptr) return std::make_pair(nullptr, nullptr);

        if (k <= getNodeSize(p->lchild)) {
            auto o = split(p->lchild, k);
            p->lchild = o.second;
            p->pushup();
            o.second = p;

            return o;
        }

        auto o = split(p->rchild, k - getNodeSize(p->lchild) - 1);
        p->rchild = o.first;
        p->pushup();
        o.first = p;

        return o;
    }

    std::pair<node *, node *> splitByValue(node *p, int value) {
        if (p == nullptr) return std::make_pair(nullptr, nullptr);

        if (p->value < value) {
            auto o = splitByValue(p->rchild, value);
            p->rchild = o.first;
            p->pushup();
            o.first = p;

            return o;
        }

        auto o = splitByValue(p->lchild, value);
        p->lchild = o.second;
        p->pushup();
        o.second = p;

        return o;
    }

    node *merge(node *x, node *y) {
        if (x == nullptr) return y;
        if (y == nullptr) return x;

        if (x->key > y->key) {
            x->rchild = merge(x->rchild, y);
            x->pushup();
            return x;
        }

        y->lchild = merge(x, y->lchild);
        y->pushup();
        return y;
    }

  public:
    Treap()
        : root(nullptr) {}

    ~Treap() {
        delete root;
    }

    inline void insert(int value) {
        auto o = splitByValue(root, value);
        o.first = merge(o.first, new node(value));
        root = merge(o.first, o.second);
    }

    inline void erase(int value) {
        auto o = splitByValue(root, value);
        auto t = split(o.second, 1);

        if (t.first->value == value) {
            delete t.first;
        }

        root = merge(o.first, t.second);
    }

    inline int rank(int value) {
        auto x = splitByValue(root, value);
        int r = getNodeSize(x.first) + 1;
        root = merge(x.first, x.second);
        return r;
    }

    inline int kth(int k) {
        auto x = split(root, k - 1);
        auto y = split(x.second, 1);
        Treap::node *o = y.first;
        root = merge(x.first, merge(y.first, y.second));
        return o == nullptr ? 0 : o->value;
    }

    inline int pre(int x) {
        int k = rank(x) - 1;
        return k > 0
                 ? kth(k)
                 : std::numeric_limits<int>::min() + 1;
    }

    inline int suc(int x) {
        int k = rank(x + 1);
        return k > getNodeSize(root)
                 ? std::numeric_limits<int>::max()
                 : kth(k);
    }
};

struct node : Treap {
    int l, r;
    node *lchild, *rchild;

    node()
        : l(0), r(0), lchild(nullptr), rchild(nullptr) {}

    node(const int &_l, const int &_r)
        : l(_l), r(_r), lchild(nullptr), rchild(nullptr) {}

    ~node() {
        if (lchild != nullptr) delete lchild;
        if (rchild != nullptr) delete rchild;
    }
} * root;

int n, m, a[N];

void build(node *&u, int l, int r) {
    u = new node(l, r);

    for (int i = l; i <= r; i++) {
        u->insert(a[i]);
    }

    if (l == r) return;

    int mid = (l + r) >> 1;

    build(u->lchild, l, mid);
    build(u->rchild, mid + 1, r);
}

int query_rank(node *u, int l, int r, int x) {
    if (l <= u->l && u->r <= r) {
        return u->rank(x) - 1;
    }

    int mid = (u->l + u->r) >> 1;
    int res = 0;

    if (l <= mid) res += query_rank(u->lchild, l, r, x);
    if (r > mid) res += query_rank(u->rchild, l, r, x);

    return res;
}

int query_kth(int _l, int _r, int k) {
    int l = 0, r = 1e8, res = -1;

    while (l <= r) {
        int mid = (l + r + 1) >> 1;

        if (query_rank(root, _l, _r, mid) + 1 <= k) {
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }

    return res;
}

void modify(node *u, int p, int x) {
    u->erase(a[p]);
    u->insert(x);

    if (u->l == u->r) return;

    int mid = (u->l + u->r) >> 1;

    if (p <= mid) modify(u->lchild, p, x);
    else modify(u->rchild, p, x);
}

int query_pre(node *u, int l, int r, int x) {
    if (l <= u->l && u->r <= r) {
        return u->pre(x);
    }

    int mid = (u->l + u->r) >> 1;
    int res = std::numeric_limits<int>::min() + 1;

    if (l <= mid) res = std::max(res, query_pre(u->lchild, l, r, x));
    if (r > mid) res = std::max(res, query_pre(u->rchild, l, r, x));

    return res;
}

int query_suc(node *u, int l, int r, int x) {
    if (l <= u->l && u->r <= r) {
        return u->suc(x);
    }

    int mid = (u->l + u->r) >> 1;
    int res = std::numeric_limits<int>::max();

    if (l <= mid) res = std::min(res, query_suc(u->lchild, l, r, x));
    if (r > mid) res = std::min(res, query_suc(u->rchild, l, r, x));

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(root, 1, n);

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int l, r, x;

            cin >> l >> r >> x;

            cout << query_rank(root, l, r, x) + 1 << endl;
        } else if (op == 2) {
            int l, r, k;

            cin >> l >> r >> k;

            cout << query_kth(l, r, k) << endl;
        } else if (op == 3) {
            int p, x;

            cin >> p >> x;

            modify(root, p, x);
            a[p] = x;
        } else if (op == 4) {
            int l, r, x;

            cin >> l >> r >> x;

            cout << query_pre(root, l, r, x) << endl;
        } else {  // op == 5
            int l, r, x;

            cin >> l >> r >> x;

            cout << query_suc(root, l, r, x) << endl;
        }
    }

    delete root;

    return 0;
}
