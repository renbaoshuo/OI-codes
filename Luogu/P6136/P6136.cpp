#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
#define endl '\n'

const int N = 2e6 + 5;

class Treap {
  private:
    struct node {
        node *left, *right;
        int size, val, key;

        node();
        node(int);
        ~node();

        void pushup();
    } * root;

    int getNodeSize(node *);
    node *find(node *, int);
    std::pair<node *, node *> split(node *, int);
    std::pair<node *, node *> splitByValue(node *, int);
    node *merge(node *, node *);
    int _getRank(node *, int);

  public:
    Treap();

    void insert(int);
    void erase(int);
    int getRank(int);
    int getKth(int);
} tree;

// struct Treap::node

Treap::node::node()
    : left(nullptr),
      right(nullptr),
      size(1),
      val(0),
      key(rand()) {}

Treap::node::node(int _val)
    : left(nullptr),
      right(nullptr),
      size(1),
      val(_val),
      key(rand()) {}

Treap::node::~node() {
    delete this->left, this->right;
}

inline void Treap::node::pushup() {
    this->size = 1;
    if (this->left != nullptr) this->size += this->left->size;
    if (this->right != nullptr) this->size += this->right->size;
}

// class Treap

Treap::Treap()
    : root(nullptr) {}

inline int Treap::getNodeSize(Treap::node *node) {
    return node == nullptr ? 0 : node->size;
}

std::pair<Treap::node *, Treap::node *> Treap::split(Treap::node *p, int k) {
    if (p == nullptr) return std::make_pair(nullptr, nullptr);
    std::pair<Treap::node *, Treap::node *> o;
    if (k <= this->getNodeSize(p->left)) {
        o = this->split(p->left, k);
        p->left = o.second;
        p->pushup();
        o.second = p;
    } else {
        o = this->split(p->right, k - this->getNodeSize(p->left) - 1);
        p->right = o.first;
        p->pushup();
        o.first = p;
    }
    return o;
}

std::pair<Treap::node *, Treap::node *> Treap::splitByValue(Treap::node *p, int val) {
    if (p == nullptr) return std::make_pair(nullptr, nullptr);
    std::pair<Treap::node *, Treap::node *> o;
    if (p->val < val) {
        o = this->splitByValue(p->right, val);
        p->right = o.first;
        p->pushup();
        o.first = p;
    } else {
        o = this->splitByValue(p->left, val);
        p->left = o.second;
        p->pushup();
        o.second = p;
    }
    return o;
}

Treap::node *Treap::merge(Treap::node *x, Treap::node *y) {
    if (x == nullptr) return y;
    if (y == nullptr) return x;
    if (x->key > y->key) {
        x->right = this->merge(x->right, y);
        x->pushup();
        return x;
    }
    y->left = this->merge(x, y->left);
    y->pushup();
    return y;
}

Treap::node *Treap::find(Treap::node *p, int val) {
    if (p == nullptr) return nullptr;
    if (p->val == val) return p;
    if (p->val > val) return this->find(p->left, val);
    return this->find(p->right, val);
}

void Treap::insert(int val) {
    auto o = this->splitByValue(this->root, val);
    o.first = this->merge(o.first, new Treap::node(val));
    this->root = this->merge(o.first, o.second);
}

void Treap::erase(int val) {
    auto o = this->splitByValue(this->root, val);
    auto t = o;
    if (this->find(o.second, val) != nullptr) {
        t = this->split(o.second, 1);
        delete t.first;
    }
    this->root = this->merge(o.first, t.second);
}

int Treap::_getRank(Treap::node *p, int val) {
    if (p == nullptr) return 1;
    if (val <= p->val) return this->_getRank(p->left, val);
    return this->getNodeSize(p->left) + 1 + this->_getRank(p->right, val);
}

inline int Treap::getRank(int val) {
    return this->_getRank(this->root, val);
}

int Treap::getKth(int k) {
    auto x = this->split(this->root, k - 1);
    auto y = this->split(x.second, 1);
    Treap::node *o = y.first;
    this->root = this->merge(x.first, this->merge(y.first, y.second));
    return o == nullptr ? -1 : o->val;
}

int n, m, op, x, last, ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    while (n--) {
        cin >> x;
        tree.insert(x);
    }
    while (m--) {
        cin >> op >> x;
        x ^= last;
        if (op == 1) {
            tree.insert(x);
        } else if (op == 2) {
            tree.erase(x);
        } else if (op == 3) {
            last = tree.getRank(x);
            ans ^= last;
        } else if (op == 4) {
            last = tree.getKth(x);
            ans ^= last;
        } else if (op == 5) {
            last = tree.getKth(tree.getRank(x) - 1);
            ans ^= last;
        } else {
            last = tree.getKth(tree.getRank(x + 1));
            ans ^= last;
        }
    }
    cout << ans << endl;
    return 0;
}
