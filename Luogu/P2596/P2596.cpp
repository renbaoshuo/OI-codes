#include <iostream>
#include <cstdlib>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 8e4 + 5;

struct node {
    node *lchild, *rchild, *fa;
    std::size_t size;
    int value, key;

    node()
        : lchild(nullptr), rchild(nullptr), fa(nullptr), size(0), value(0), key(rand()) {}

    node(int _value)
        : lchild(nullptr), rchild(nullptr), fa(nullptr), size(1), value(_value), key(rand()) {}

    ~node() {
        if (lchild != nullptr) delete lchild;
        if (rchild != nullptr) delete rchild;
    }

    inline std::size_t lsize() {
        return lchild == nullptr ? 0 : lchild->size;
    }

    inline std::size_t rsize() {
        return rchild == nullptr ? 0 : rchild->size;
    }

    inline void pushup() {
        size = 1;

        if (lchild != nullptr) {
            size += lchild->size;
            lchild->fa = this;
        }

        if (rchild != nullptr) {
            size += rchild->size;
            rchild->fa = this;
        }
    }

    inline std::size_t pos() {
        std::size_t ret = lsize() + 1;
        node *cur = this;

        while (cur->fa != nullptr) {
            if (cur->fa->rchild == cur) {
                ret += cur->fa->lsize() + 1;
            }

            cur = cur->fa;
        }

        return ret;
    }
};

int n, m;
node *root, *p[N];

std::pair<node *, node *> split(node *u, int k) {
    if (u == nullptr) return std::make_pair(nullptr, nullptr);

    if (k <= u->lsize()) {
        auto o = split(u->lchild, k);

        u->lchild = o.second;
        u->pushup();
        o.second = u;

        return o;
    }

    auto o = split(u->rchild, k - u->lsize() - 1);

    u->rchild = o.first;
    u->pushup();
    o.first = u;

    return o;
}

template <typename... Args>
node *merge(node *x, Args... args) {
    return merge(x, merge(args...));
}

template <>
node *merge(node *x, node *y) {
    if (x == nullptr) return y;
    if (y == nullptr) return x;

    if (x->key < y->key) {
        x->rchild = merge(x->rchild, y);
        x->pushup();

        return x;
    }

    y->lchild = merge(x, y->lchild);
    y->pushup();

    return y;
}

inline void top(const int &x) {
    int k = p[x]->pos();

    auto p = split(root, k - 1);
    auto q = split(p.second, 1);

    root = merge(q.first, p.first, q.second);
}

inline void bottom(const int &x) {
    int k = p[x]->pos();

    auto p = split(root, k - 1);
    auto q = split(p.second, 1);

    root = merge(p.first, q.second, q.first);
}

inline void insert(const int &x, const int &y) {
    if (!y) return;

    int k = p[x]->pos();
    auto p = split(root, k - 1);
    auto q = split(p.second, 1);

    if (y > 0) {
        auto t = split(q.second, y);
        root = merge(p.first, t.first, q.first, t.second);
    } else {  // y < 0
        auto t = split(p.first, k + y - 1);
        root = merge(t.first, q.first, t.second, q.second);
    }
}

inline int ask(const int &x) {
    return p[x]->pos() - 1;
}

inline int query(const int &x) {
    auto p = split(root, x - 1);
    auto q = split(p.second, 1);

    int res = q.first->value;

    root = merge(p.first, q.first, q.second);

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        root = merge(root, p[x] = new node(x));
    }

    while (m--) {
        std::string op;
        int s, t;

        cin >> op >> s;

        switch (op[0]) {
            case 'T': {  // op == "Top"
                top(s);

                break;
            }
            case 'B': {  // op == "Bottom"
                bottom(s);

                break;
            }
            case 'I': {  // op == "Insert"
                cin >> t;

                insert(s, t);

                break;
            }
            case 'A': {  // op == "Ask"
                cout << ask(s) << endl;

                break;
            }
            case 'Q': {  // op == "Query"
                cout << query(s) << endl;

                break;
            }
        }
    }

    // Cleanup
    delete root;

    return 0;
}
