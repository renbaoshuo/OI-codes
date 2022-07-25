#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5;

class Splay {
  private:
    struct node {
        int value;
        node *lchild, *rchild, *parent, **root;
        size_t size, count;

        node()
            : value(0), lchild(nullptr), rchild(nullptr), parent(nullptr), root(nullptr), size(0), count(0) {}

        node(const int &_value, node *_parent, node **_root)
            : value(_value), lchild(nullptr), rchild(nullptr), parent(_parent), root(_root), size(1), count(1) {}

        ~node() {
            if (lchild != nullptr) delete lchild;
            if (rchild != nullptr) delete rchild;
        }

        node *&child(unsigned int x) {
            return !x ? lchild : rchild;
        }

        unsigned relation() const {
            return this == parent->lchild ? 0 : 1;
        }

        size_t lsize() const {
            return lchild == nullptr ? 0 : lchild->size;
        }

        size_t rsize() const {
            return rchild == nullptr ? 0 : rchild->size;
        }

        void pushup() {
            size = lsize() + count + rsize();
        }

        void rotate() {
            node *old = parent;
            unsigned x = relation();

            if (old->parent != nullptr) {
                old->parent->child(old->relation()) = this;
            }
            parent = old->parent;

            if (child(x ^ 1) != nullptr) {
                child(x ^ 1)->parent = old;
            }
            old->child(x) = child(x ^ 1);

            child(x ^ 1) = old;
            old->parent = this;

            old->pushup();
            pushup();
        }

        void splay(node *target = nullptr) {
            while (parent != target) {
                if (parent->parent == target) {
                    rotate();
                } else if (relation() == parent->relation()) {
                    parent->rotate();
                    rotate();
                } else {
                    rotate();
                    rotate();
                }
            }

            if (target == nullptr) *root = this;
        }

        node *predecessor() {
            node *pred = lchild;

            while (pred->rchild != nullptr) {
                pred = pred->rchild;
            }

            return pred;
        }

        node *successor() {
            node *succ = rchild;

            while (succ->lchild != nullptr) {
                succ = succ->lchild;
            }

            return succ;
        }
    } * root;

    node *_insert(const int &value) {
        node **target = &root, *parent = nullptr;

        while (*target != nullptr && (*target)->value != value) {
            parent = *target;
            parent->size++;

            if (value < parent->value) {
                target = &parent->lchild;
            } else {
                target = &parent->rchild;
            }
        }

        if (*target == nullptr) {
            *target = new node(value, parent, &root);
        } else {
            (*target)->count++;
            (*target)->size++;
        }

        (*target)->splay();

        return root;
    }

    node *find(const int &value) {
        node *node = root;

        while (node != nullptr && value != node->value) {
            if (value < node->value) {
                node = node->lchild;
            } else {
                node = node->rchild;
            }
        }

        if (node != nullptr) {
            node->splay();
        }

        return node;
    }

    void erase(node *u) {
        if (u == nullptr) return;

        if (u->count > 1) {
            u->splay();
            u->count--;
            u->size--;

            return;
        }

        node *pred = u->predecessor(),
             *succ = u->successor();

        pred->splay();
        succ->splay(pred);

        delete succ->lchild;
        succ->lchild = nullptr;

        succ->pushup();
        pred->pushup();
    }

  public:
    Splay()
        : root(nullptr) {
        insert(std::numeric_limits<int>::min());
        insert(std::numeric_limits<int>::max());
    }

    ~Splay() {
        delete root;
    }

    void insert(const int &value) {
        _insert(value);
    }

    void erase(const int &value) {
        erase(find(value));
    }

    unsigned rank(const int &value) {
        node *node = find(value);

        if (node == nullptr) {
            node = _insert(value);
            int res = node->lsize();
            erase(node);

            return res;
        }

        return node->lsize();
    }

    const int &predecessor(const int &value) {
        node *node = find(value);

        if (node == nullptr) {
            node = _insert(value);
            const int &result = node->predecessor()->value;
            erase(node);
            return result;
        }

        return node->predecessor()->value;
    }

    const int &successor(const int &value) {
        node *node = find(value);

        if (node == nullptr) {
            node = _insert(value);
            const int &result = node->successor()->value;
            erase(node);
            return result;
        }

        return node->successor()->value;
    }
};

struct node : Splay {
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
    int l = -1e8, r = 1e8, res = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;

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
        return u->predecessor(x);
    }

    int mid = (u->l + u->r) >> 1;
    int res = std::numeric_limits<int>::min();

    if (l <= mid) res = std::max(res, query_pre(u->lchild, l, r, x));
    if (r > mid) res = std::max(res, query_pre(u->rchild, l, r, x));

    return res;
}

int query_suf(node *u, int l, int r, int x) {
    if (l <= u->l && u->r <= r) {
        return u->successor(x);
    }

    int mid = (u->l + u->r) >> 1;
    int res = std::numeric_limits<int>::max();

    if (l <= mid) res = std::min(res, query_suf(u->lchild, l, r, x));
    if (r > mid) res = std::min(res, query_suf(u->rchild, l, r, x));

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

            cout << query_suf(root, l, r, x) << endl;
        }
    }

    delete root;

    return 0;
}
