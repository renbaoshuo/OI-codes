#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

struct node {
    node *lchild, *rchild;
    size_t size;
    unsigned key;
    int value, min;
    bool reversed;

    node()
        : lchild(nullptr),
          rchild(nullptr),
          size(0),
          key(rand()),
          value(0),
          min(std::numeric_limits<int>::max()),
          reversed(false) {}

    node(int _value)
        : lchild(nullptr),
          rchild(nullptr),
          size(1),
          key(rand()),
          value(_value),
          min(_value),
          reversed(false) {}

    ~node() {
        if (lchild != nullptr) delete lchild;
        if (rchild != nullptr) delete rchild;
    }

    inline size_t lsize() {
        return lchild == nullptr ? 0 : lchild->size;
    }

    inline size_t rsize() {
        return rchild == nullptr ? 0 : rchild->size;
    }

    inline void pushup() {
        size = lsize() + 1 + rsize();
        min = value;

        if (lchild != nullptr) {
            min = std::min(min, lchild->min);
        }

        if (rchild != nullptr) {
            min = std::min(min, rchild->min);
        }
    }

    inline void pushdown() {
        if (reversed) {
            std::swap(lchild, rchild);
            if (lchild != nullptr) lchild->reversed = !lchild->reversed;
            if (rchild != nullptr) rchild->reversed = !rchild->reversed;
            reversed = false;
        }
    }
};

int n, b[N];
std::pair<int, int> a[N];
node *root;

std::pair<node *, node *> split(node *u, int k) {
    if (u == nullptr) return std::make_pair(nullptr, nullptr);

    u->pushdown();

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

node *merge(node *x, node *y) {
    if (x == nullptr) return y;
    if (y == nullptr) return x;

    if (x->key < y->key) {
        x->pushdown();
        x->rchild = merge(x->rchild, y);
        x->pushup();

        return x;
    }

    y->pushdown();
    y->lchild = merge(x, y->lchild);
    y->pushup();

    return y;
}

void reverse(int k) {
    auto x = split(root, k);
    auto y = split(x.first, k - 1);
    if (y.first != nullptr) y.first->reversed = !y.first->reversed;
    delete y.second;
    root = merge(y.first, x.second);
}

int find(node *p) {
    int k = 1;

    while (p != nullptr) {
        p->pushdown();

        if (p->lchild != nullptr && p->min == p->lchild->min) {
            p = p->lchild;
        } else if (p->rchild != nullptr && p->min == p->rchild->min) {
            k += p->lsize() + 1;
            p = p->rchild;
        } else {
            return k + p->lsize();
        }
    }

    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;

            a[i].second = i;
        }

        std::sort(a + 1, a + 1 + n);

        for (int i = 1; i <= n; i++) {
            b[a[i].second] = i;
        }

        for (int i = 1; i <= n; i++) {
            root = merge(root, new node(b[i]));
        }

        for (int i = 1; i <= n; i++) {
            int k = find(root);

            reverse(k);

            cout << k + i - 1 << (i == n ? '\n' : ' ');
        }

        // Cleanup
        delete root;
        root = nullptr;
    }

    return 0;
}
