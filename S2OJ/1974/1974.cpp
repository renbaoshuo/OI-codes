#include <iostream>
#include <functional>
#include <memory>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

template <typename T, class Compare = std::less<T>>
class LeftistTree : public std::enable_shared_from_this<LeftistTree<T, Compare>> {
  public:
    using pointer_type = std::shared_ptr<LeftistTree<T, Compare>>;

  protected:
    static Compare comp;

  private:
    size_t dist;
    pointer_type lchild, rchild;
    std::weak_ptr<LeftistTree<T, Compare>> root;

  public:
    T id, val;

    LeftistTree(const T& _val = 0, const T& _id = 0)
        : dist(0),
          lchild(nullptr),
          rchild(nullptr),
          root(),
          id(_id),
          val(_val) {}

    pointer_type find_root() {
        std::stack<pointer_type> st;
        pointer_type cur = this->shared_from_this();

        st.emplace(cur);

        while (auto ptr = cur->root.lock()) {
            st.emplace(cur = ptr);
        }

        while (!st.empty()) {
            auto ptr = st.top();
            st.pop();

            ptr->root = cur;
        }

        cur->root.reset();

        return cur;
    }

    void erase() {
        if (lchild) lchild->root.reset();
        if (rchild) rchild->root.reset();

        root = merge(lchild, rchild);
    }

    static pointer_type merge(pointer_type x, pointer_type y) {
        if (!x) return y;
        if (!y) return x;

        if (comp(x->val, y->val) || x->val == y->val && comp(x->id, y->id)) std::swap(x, y);

        x->rchild = merge(x->rchild, y);

        if (!x->lchild || x->lchild->dist < x->rchild->dist) std::swap(x->lchild, x->rchild);

        if (x->lchild) x->lchild->root = x;
        if (x->rchild) x->rchild->root = x;

        x->dist = x->rchild ? x->rchild->dist + 1 : 0;

        return x;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    std::vector<bool> exists(n + 1, true);
    std::vector<LeftistTree<int, std::greater<>>::pointer_type> tr(n + 1);

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        tr[i] = std::make_shared<decltype(tr)::value_type::element_type>(x, i);
    }

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int x, y;

            cin >> x >> y;

            if (exists[x] && exists[y]) {
                auto fx = tr[x]->find_root(),
                     fy = tr[y]->find_root();

                if (fx != fy) {
                    decltype(tr)::value_type::element_type::merge(fx, fy);
                }
            }
        } else {  // op == 2
            int x;

            cin >> x;

            if (exists[x]) {
                auto fx = tr[x]->find_root();

                if (exists[fx->id]) {
                    cout << fx->val << endl;

                    fx->erase();
                    exists[fx->id] = false;
                } else {
                    cout << -1 << endl;
                }
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
