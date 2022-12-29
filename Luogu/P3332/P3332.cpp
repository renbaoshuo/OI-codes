#include <iostream>
#include <functional>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

template <typename T>
class SegmentTree {
  private:
    struct node {
        int l, r;
        T sum, tag;
        node *lchild, *rchild;

        node(const int &_l = 0, const int &_r = 0)
            : l(_l), r(_r), sum(0), tag(0), lchild(nullptr), rchild(nullptr) {}

        ~node() {
            if (lchild) delete lchild;
            if (rchild) delete rchild;
        }

        void pushup() {
            sum = 0;

            if (lchild != nullptr) sum += lchild->sum;
            if (rchild != nullptr) sum += rchild->sum;
        }

        void pushdown() {
            int mid = l + r >> 1;

            if (lchild == nullptr) lchild = new node(l, mid);
            if (rchild == nullptr) rchild = new node(mid + 1, r);

            lchild->sum += static_cast<T>(lchild->r - lchild->l + 1) * tag;
            lchild->tag += tag;

            rchild->sum += static_cast<T>(rchild->r - rchild->l + 1) * tag;
            rchild->tag += tag;

            tag = 0;
        }
    };

    const int n;
    node *root;

    void modify(node *&cur, int l, int r, int ql, int qr, T val) {
        if (cur == nullptr) cur = new node(l, r);

        if (ql <= l && r <= qr) {
            cur->sum += static_cast<T>(r - l + 1) * val;
            cur->tag += val;

            return;
        }

        int mid = l + r >> 1;

        cur->pushdown();

        if (ql <= mid) modify(cur->lchild, l, mid, ql, qr, val);
        if (qr > mid) modify(cur->rchild, mid + 1, r, ql, qr, val);

        cur->pushup();
    }

    T query(node *cur, int l, int r, int ql, int qr) {
        if (cur == nullptr) return T();
        if (ql <= l && r <= qr) return cur->sum;

        int mid = l + r >> 1;
        T res = 0;

        cur->pushdown();

        if (ql <= mid) res += query(cur->lchild, l, mid, ql, qr);
        if (qr > mid) res += query(cur->rchild, mid + 1, r, ql, qr);

        return res;
    }

  public:
    SegmentTree(const int &_n)
        : n(_n), root(nullptr) {}

    ~SegmentTree() {
        if (root) delete root;
    }

    void modify(int ql, int qr, T val) {
        modify(root, 1, n, ql, qr, val);
    }

    T query(int ql, int qr) {
        return query(root, 1, n, ql, qr);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, cnt = 0;
    std::vector<std::tuple<int, int, int, long long, int>> qs;

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int op, l, r;
        long long k;

        cin >> op >> l >> r >> k;

        if (op == 1) {
            qs.emplace_back(op, l, r, k, -1);
        } else {  // op == 2
            qs.emplace_back(op, l, r, k, cnt++);
        }
    }

    std::vector<int> ans(cnt);
    SegmentTree<long long> tr(n);

    std::function<void(const std::vector<std::tuple<int, int, int, long long, int>> &, int, int)> solve = [&](const std::vector<std::tuple<int, int, int, long long, int>> &qs, int l, int r) -> void {
        if (qs.empty()) return;

        if (l == r) {
            for (auto o : qs) {
                int op, id;

                std::tie(op, std::ignore, std::ignore, std::ignore, id) = o;

                if (op == 2) ans[id] = l;
            }

            return;
        }

        int mid = l + r >> 1;
        std::vector<std::tuple<int, int, int, long long, int>> ql, qr;
        std::vector<long long> cur(qs.size());

        for (int i = 0; i < qs.size(); i++) {
            int op, l, r;
            long long k;

            std::tie(op, l, r, k, std::ignore) = qs[i];

            if (op == 1) {
                if (k > mid) tr.modify(l, r, 1);
            } else {  // op == 2
                cur[i] = tr.query(l, r);
            }
        }

        for (int i = 0; i < qs.size(); i++) {
            int op, l, r;
            long long k;

            std::tie(op, l, r, k, std::ignore) = qs[i];

            if (op == 1 && k > mid) {
                tr.modify(l, r, -1);
            }
        }

        for (int i = 0; i < qs.size(); i++) {
            int op, l, r, id;
            long long k;

            std::tie(op, l, r, k, id) = qs[i];

            if (op == 1) {
                if (k <= mid) ql.emplace_back(qs[i]);
                else qr.emplace_back(qs[i]);
            } else {  // op == 2
                if (cur[i] < k) {
                    ql.emplace_back(op, l, r, k - cur[i], id);
                } else {
                    qr.emplace_back(qs[i]);
                }
            }
        }

        solve(ql, l, mid);
        solve(qr, mid + 1, r);
    };

    solve(qs, 0, n);

    for (int x : ans) cout << x << endl;

    return 0;
}
