#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

class Splay {
  private:
    size_t root, cnt;

    struct node {
        size_t l, r, f, c, s;
        int v;

        node()
            : l(0), r(0), f(0), c(0), s(0), v(0) {}

        node(int _v, int _f)
            : l(0), r(0), f(_f), c(1), s(1), v(_v) {}

        size_t &child(unsigned x) {
            return !x ? l : r;
        }
    } tr[N];

    // 上传信息
    void pushup(size_t u) {
        tr[u].s = tr[tr[u].l].s + tr[tr[u].r].s + tr[u].c;
    }

    unsigned relation(size_t u) {
        // 如果当前节点是其父亲节点的左儿子则返回 0，否则返回 1
        return u == tr[tr[u].f].l ? 0 : 1;
    }

    void rotate(size_t u) {
        // 旧的父节点
        size_t p = tr[u].f;

        // 当前节点与父节点之间的关系
        unsigned x = relation(u);

        // 当前节点 <-> 父节点的父节点
        if (tr[p].f) {
            tr[tr[p].f].child(relation(p)) = u;
        }
        tr[u].f = tr[p].f;

        // 原先的另一个子节点 <-> 父节点
        if (tr[u].child(x ^ 1)) {
            tr[tr[u].child(x ^ 1)].f = p;
        }
        tr[p].child(x) = tr[u].child(x ^ 1);

        // 原先的父节点 -> 子节点
        tr[u].child(x ^ 1) = p;
        tr[p].f = u;

        // 更新节点信息
        pushup(p);
        pushup(u);
    }

    // Splay
    //
    // 旋转到给定的位置（target），默认行为为旋转为根节点
    void splay(size_t u, size_t t = 0) {
        while (tr[u].f != t) {
            if (tr[tr[u].f].f == t) {
                rotate(u);
            } else if (relation(u) == relation(tr[u].f)) {
                rotate(tr[u].f);
                rotate(u);
            } else {
                rotate(u);
                rotate(u);
            }
        }

        // 更新根节点
        if (!t) root = u;
    }

    // 前驱
    //
    // 左子树的最右点
    size_t _predecessor(size_t u) {
        size_t cur = tr[u].l;

        while (tr[cur].r) {
            cur = tr[cur].r;
        }

        return cur;
    }

    // 后继
    //
    // 右子树的最左点
    size_t _successor(size_t u) {
        size_t cur = tr[u].r;

        while (tr[cur].l) {
            cur = tr[cur].l;
        }

        return cur;
    }

    size_t _find(const int &v) {
        size_t u = root;

        while (u && tr[u].v != v) {
            // 根据数值大小向左右子树迭代
            u = v < tr[u].v ? tr[u].l : tr[u].r;
        }

        if (u) splay(u);

        return u;
    }

    size_t _insert(const int &v) {
        size_t u = root, f = 0;

        while (u && tr[u].v != v) {
            f = u;
            // 根据数值大小向左右子树迭代
            u = v < tr[u].v ? tr[u].l : tr[u].r;
        }

        if (u) {
            tr[u].c++;
            tr[u].s++;
        } else {
            tr[u = ++cnt] = node(v, f);
            if (f) tr[f].child(v > tr[f].v) = u;
        }

        splay(u);

        return root;
    }

    void _erase(size_t u) {
        if (!u) return;

        if (tr[u].c > 1) {  // 存在重复的数
            splay(u);
            tr[u].c--;
            tr[u].s--;

            return;
        }

        size_t pred = _predecessor(u),
               succ = _successor(u);

        splay(pred);        // 将前驱旋转到根节点
        splay(succ, pred);  // 将后继旋转到根节点的右儿子

        tr[succ].l = 0;  // 此时要删的节点为根节点的左儿子且为叶子节点

        // 更新节点信息
        pushup(succ);
        pushup(pred);
    }

  public:
    Splay()
        : root(0), cnt(0) {
        // 插入哨兵节点
        insert(std::numeric_limits<int>::min());
        insert(std::numeric_limits<int>::max());
    }

    // 插入
    void insert(const int &v) {
        _insert(v);
    }

    // 删除
    void erase(const int &v) {
        _erase(_find(v));
    }

    // 排名
    unsigned rank(const int &v) {
        size_t u = _find(v);

        if (!u) {  // 不存在则插入一个方便查找
            u = _insert(v);

            // 此时 u 已经成为根节点，直接取左子树大小即可
            unsigned r = tr[tr[u].l].s;

            _erase(u);

            return r;
        }

        return tr[tr[u].l].s;
    }

    // 选择
    const int &select(unsigned k) {
        size_t u = root;

        while (k < tr[tr[u].l].s || k >= tr[tr[u].l].s + tr[u].c) {
            if (k < tr[tr[u].l].s) {
                u = tr[u].l;
            } else {
                k -= tr[tr[u].l].s + tr[u].c;
                u = tr[u].r;
            }
        }

        splay(u);

        return tr[u].v;
    }

    // 前驱
    const int &predecessor(const int &v) {
        size_t u = _find(v);

        if (!u) {  // 不存在则插入一个方便查找
            u = _insert(v);

            const int &r = tr[_predecessor(u)].v;

            _erase(u);  // 删除

            return r;
        }

        return tr[_predecessor(u)].v;
    }

    // 后继
    const int &successor(const int &v) {
        size_t u = _find(v);

        if (!u) {  // 不存在则插入一个方便查找
            u = _insert(v);

            const int &r = tr[_successor(u)].v;

            _erase(u);  // 删除

            return r;
        }

        return tr[_successor(u)].v;
    }
};

int n;
Splay tree;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    while (n--) {
        int op, x;

        cin >> op >> x;

        if (op == 1) {
            tree.insert(x);
        } else if (op == 2) {
            tree.erase(x);
        } else if (op == 3) {
            cout << tree.rank(x) << endl;
        } else if (op == 4) {
            cout << tree.select(x) << endl;
        } else if (op == 5) {
            cout << tree.predecessor(x) << endl;
        } else {  // op == 6
            cout << tree.successor(x) << endl;
        }
    }

    return 0;
}
