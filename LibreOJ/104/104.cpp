#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

template <typename T>
class Splay {
  private:
    struct node {
        T value;
        node *lchild, *rchild, *parent, **root;
        std::size_t size, count;

        node()
            : value(0), lchild(nullptr), rchild(nullptr), parent(nullptr), root(nullptr), size(0), count(0) {}

        node(const T &_value, node *_parent, node **_root)
            : value(_value), lchild(nullptr), rchild(nullptr), parent(_parent), root(_root), size(1), count(1) {}

        ~node() {
            if (lchild != nullptr) delete lchild;
            if (rchild != nullptr) delete rchild;
        }

        node *&child(unsigned int x) {
            return !x ? lchild : rchild;
        }

        unsigned int relation() const {
            // 如果当前节点是其父亲节点的左儿子则返回 0，否则返回 1
            return this == parent->lchild ? 0 : 1;
        }

        // 左儿子大小
        std::size_t lsize() const {
            return lchild == nullptr ? 0 : lchild->size;
        }

        // 右儿子大小
        std::size_t rsize() const {
            return rchild == nullptr ? 0 : rchild->size;
        }

        // 上传信息
        void pushup() {
            size = lsize() + count + rsize();
        }

        // 旋转
        void rotate() {
            node *old = parent;
            unsigned int x = relation();

            if (old->parent != nullptr) {
                old->parent->child(old->relation()) = this;
            }
            parent = old->parent;

            old->child(x) = child(x ^ 1);
            if (child(x ^ 1) != nullptr) {
                child(x ^ 1)->parent = old;
            }

            child(x ^ 1) = old;
            old->parent = this;

            old->pushup();
            pushup();

            if (parent == nullptr) *root = this;
        }

        // Splay
        void splay(node *target = nullptr) {
            while (parent != target) {
                if (parent->parent == target) {  // 父节点是目标节点
                    rotate();
                } else if (relation() == parent->relation()) {  // 关系相同
                    parent->rotate();
                    rotate();
                } else {
                    rotate();
                    rotate();
                }
            }
        }

        // 前驱：左子树的最右点
        node *predecessor() {
            node *pred = lchild;

            while (pred->rchild != nullptr) {
                pred = pred->rchild;
            }

            return pred;
        }

        // 后继：右子树的最左点
        node *successor() {
            node *succ = rchild;

            while (succ->lchild != nullptr) {
                succ = succ->lchild;
            }

            return succ;
        }
    } * root;

    // 插入（内部函数）
    node *_insert(const T &value) {
        node **target = &root, *parent = nullptr;

        while (*target != nullptr && (*target)->value != value) {
            parent = *target;
            parent->size++;

            // 根据大小向左右子树迭代
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

    // 查找指定的值对应的节点
    node *find(const T &value) {
        node *node = root;  // 从根节点开始查找

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

    // 删除
    void erase(node *u) {
        if (u == nullptr) return;

        if (u->count > 1) {  // 存在重复的数
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
        insert(std::numeric_limits<T>::min());
        insert(std::numeric_limits<T>::max());
    }

    ~Splay() {
        delete root;
    }

    // 插入
    void insert(const T &value) {
        _insert(value);
    }

    // 删除
    void erase(const T &value) {
        node *node = find(value);

        if (node == nullptr) return;

        erase(node);
    }

    // 排名
    unsigned int rank(const T &value) {
        node *node = find(value);

        if (node == nullptr) {
            node = _insert(value);
            // 此时 node 已经成为根节点，直接计算即可
            int res = node->lsize();  // 由于「哨兵」的存在，此处无需 -1
            erase(node);

            return res;
        }

        // 此时 node 已经成为根节点，直接计算即可
        return node->lsize();
    }

    // 选择
    const T &select(int k) {
        node *node = root;

        while (k < node->lsize() || k >= node->lsize() + node->count) {
            if (k < node->lsize()) {  // 所需的节点在左子树中
                node = node->lchild;
            } else {
                k -= node->lsize() + node->count;
                node = node->rchild;
            }
        }

        node->splay();

        return node->value;
    }

    // 前驱
    const T &predecessor(const T &value) {
        node *node = find(value);

        if (node == nullptr) {
            node = _insert(value);
            const T &result = node->predecessor()->value;
            erase(node);
            return result;
        }

        return node->predecessor()->value;
    }

    // 后继
    const T &successor(const T &value) {
        node *node = find(value);

        if (node == nullptr) {
            node = _insert(value);
            const T &result = node->successor()->value;
            erase(node);
            return result;
        }

        return node->successor()->value;
    }
};

int n;
Splay<int> tree;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int op, x;

        cin >> op >> x;

        switch (op) {
            case 1: {
                tree.insert(x);

                break;
            }
            case 2: {
                tree.erase(x);

                break;
            }
            case 3: {
                cout << tree.rank(x) << endl;

                break;
            }
            case 4: {
                cout << tree.select(x) << endl;

                break;
            }
            case 5: {
                cout << tree.predecessor(x) << endl;

                break;
            }
            case 6: {
                cout << tree.successor(x) << endl;

                break;
            }
        }
    }

    return 0;
}
