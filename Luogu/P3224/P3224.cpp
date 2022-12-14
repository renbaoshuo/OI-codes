#include <iostream>
#include <cstdlib>
#include <limits>
#include <numeric>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

class Treap {
  private:
    struct node {
        node *left, *right;
        int size, val, key;

        node(const int &_val = 0)
            : left(nullptr), right(nullptr), size(1), val(_val), key(rand()) {}

        ~node() {
            delete left;
            delete right;
        }

        void pushup() {
            size = 1;

            if (left != nullptr) size += left->size;
            if (right != nullptr) size += right->size;
        }
    } * root;

    inline int getNodeSize(node *node) {
        return node == nullptr ? 0 : node->size;
    }

    node *find(node *p, int val) {
        if (p == nullptr) return nullptr;
        if (p->val == val) return p;
        if (p->val > val) return find(p->left, val);
        return find(p->right, val);
    }

    std::pair<node *, node *> split(node *p, int k) {
        if (p == nullptr) return std::make_pair(nullptr, nullptr);

        std::pair<node *, node *> o;

        if (k <= getNodeSize(p->left)) {
            o = split(p->left, k);
            p->left = o.second;
            p->pushup();
            o.second = p;
        } else {
            o = split(p->right, k - getNodeSize(p->left) - 1);
            p->right = o.first;
            p->pushup();
            o.first = p;
        }

        return o;
    }

    std::pair<node *, node *> splitByValue(node *p, int val) {
        if (p == nullptr) return std::make_pair(nullptr, nullptr);

        std::pair<node *, node *> o;

        if (p->val < val) {
            o = splitByValue(p->right, val);
            p->right = o.first;
            p->pushup();
            o.first = p;
        } else {
            o = splitByValue(p->left, val);
            p->left = o.second;
            p->pushup();
            o.second = p;
        }

        return o;
    }

    node *merge(node *x, node *y) {
        if (x == nullptr) return y;
        if (y == nullptr) return x;

        if (x->key > y->key) {
            x->right = merge(x->right, y);
            x->pushup();
            return x;
        }

        y->left = merge(x, y->left);
        y->pushup();

        return y;
    }

    void _merge(node *cur) {
        if (cur->left != nullptr) _merge(cur->left);
        if (cur->right != nullptr) _merge(cur->right);

        insert(cur->val);
    }

  public:
    Treap()
        : root(nullptr) {}

    ~Treap() {
        delete root;
    }

    void insert(int val) {
        auto o = splitByValue(root, val);
        o.first = merge(o.first, new Treap::node(val));
        root = merge(o.first, o.second);
    }

    void erase(int val) {
        auto o = splitByValue(root, val);
        auto t = o;

        if (find(o.second, val) != nullptr) {
            t = split(o.second, 1);
            delete t.first;
        }

        root = merge(o.first, t.second);
    }

    int getRank(int val) {
        auto x = splitByValue(root, val);
        int r = getNodeSize(x.first) + 1;

        root = merge(x.first, x.second);

        return r;
    }

    int getKth(int k) {
        auto x = split(root, k - 1);
        auto y = split(x.second, 1);

        Treap::node *o = y.first;

        root = merge(x.first, merge(y.first, y.second));

        return o == nullptr ? 0 : o->val;
    }

    int size() {
        return getNodeSize(root);
    }

    void merge(Treap &b) {
        _merge(b.root);
    }
} tr[N];

int n, m, q, a[N], fa[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x != y) {
        if (tr[x].size() < tr[y].size()) {
            fa[x] = y;
            tr[y].merge(tr[x]);
        } else {
            fa[y] = x;
            tr[x].merge(tr[y]);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    a[0] = -1;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        a[x] = i;
        fa[i] = i;
        tr[i].insert(x);
    }

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        merge(u, v);
    }

    cin >> q;

    while (q--) {
        char op;
        int x, y;

        cin >> op >> x >> y;

        if (op == 'Q') {
            auto &t = tr[find(x)];

            if (t.size() < y) {
                cout << -1 << endl;
            } else {
                cout << a[t.getKth(y)] << endl;
            }
        } else {  // op == 'B'
            merge(x, y);
        }
    }

    return 0;
}
