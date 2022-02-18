#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
#define endl '\n'

const int N = 100005;

class Treap {
  private:
    int root, cnt;

    struct node {
        int l, r, s, v, k;

        node();
        node(int);
    } tr[N];

    void pushup(int);
    std::pair<int, int> split(int, int);
    std::pair<int, int> splitByValue(int, int);
    int merge(int, int);
    int find(int, int);

  public:
    void insert(int);
    void erase(int);
    int getRank(int);
    int getKth(int);
} tree;

int n, op, x;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> op >> x;
        if (op == 1) {
            tree.insert(x);
        } else if (op == 2) {
            tree.erase(x);
        } else if (op == 3) {
            cout << tree.getRank(x) << endl;
        } else if (op == 4) {
            cout << tree.getKth(x) << endl;
        } else if (op == 5) {
            cout << tree.getKth(tree.getRank(x) - 1) << endl;
        } else {
            cout << tree.getKth(tree.getRank(x + 1)) << endl;
        }
    }
    return 0;
}

// === Treap ===

// struct Treap::node

Treap::node::node()
    : l(0), r(0), s(0), v(0), k(rand()) {}
Treap::node::node(int _v)
    : l(0), r(0), s(1), v(_v), k(rand()) {}

// class Treap

inline void Treap::pushup(int u) {
    this->tr[u].s = this->tr[this->tr[u].l].s + this->tr[this->tr[u].r].s + 1;
}

std::pair<int, int> Treap::split(int p, int k) {
    if (!p) return std::make_pair(0, 0);
    if (k <= this->tr[this->tr[p].l].s) {
        auto o = this->split(this->tr[p].l, k);
        this->tr[p].l = o.second;
        this->pushup(p);
        o.second = p;
        return o;
    }
    auto o = this->split(this->tr[p].r, k - this->tr[this->tr[p].l].s - 1);
    this->tr[p].r = o.first;
    this->pushup(p);
    o.first = p;
    return o;
}

std::pair<int, int> Treap::splitByValue(int p, int v) {
    if (!p) return std::make_pair(0, 0);
    if (this->tr[p].v < v) {
        auto o = this->splitByValue(tr[p].r, v);
        this->tr[p].r = o.first;
        this->pushup(p);
        o.first = p;
        return o;
    }
    auto o = splitByValue(this->tr[p].l, v);
    this->tr[p].l = o.second;
    this->pushup(p);
    o.second = p;
    return o;
}

int Treap::merge(int x, int y) {
    if (!x) return y;
    if (!y) return x;
    if (this->tr[x].k > this->tr[y].k) {
        this->tr[x].r = merge(this->tr[x].r, y);
        this->pushup(x);
        return x;
    }
    this->tr[y].l = merge(x, this->tr[y].l);
    this->pushup(y);
    return y;
}

int Treap::find(int p, int v) {
    if (!p) return 0;
    if (this->tr[p].v == v) return p;
    if (this->tr[p].v > v) return this->find(this->tr[p].l, v);
    return this->find(this->tr[p].r, v);
}

void Treap::insert(int v) {
    auto o = this->splitByValue(root, v);
    int p = ++this->cnt;
    this->tr[p] = Treap::node(v);
    o.first = this->merge(o.first, p);
    this->root = this->merge(o.first, o.second);
}

void Treap::erase(int v) {
    auto o = this->splitByValue(root, v);
    auto t = o;
    if (this->find(o.second, v)) {
        t = this->split(o.second, 1);
    }
    this->root = this->merge(o.first, t.second);
}

inline int Treap::getRank(int v) {
    auto x = this->splitByValue(this->root, v);
    int r = this->tr[x.first].s;
    this->root = merge(x.first, x.second);
    return ++r;
}

int Treap::getKth(int k) {
    auto x = this->split(this->root, k - 1);
    auto y = this->split(x.second, 1);
    int o = y.first;
    this->root = this->merge(x.first, this->merge(y.first, y.second));
    return tr[o].v;
}
