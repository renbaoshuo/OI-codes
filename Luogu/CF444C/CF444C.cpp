#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

struct node {
    int l, r;
    int color, new_color;
    long long sum, sum_delta;
    node *lchild, *rchild;

    node()
        : l(0), r(0), color(-1), new_color(-1), sum(0), sum_delta(0), lchild(nullptr), rchild(nullptr) {}

    node(int _l, int _r)
        : l(_l), r(_r), color(-1), new_color(-1), sum(0), sum_delta(0), lchild(nullptr), rchild(nullptr) {}

    ~node() {
        delete lchild;
        delete rchild;
    }

    void pushup() {
        sum = 0;
        color = -1;

        if (lchild != nullptr) {
            sum += lchild->sum;
            color = lchild->color;
        }

        if (rchild != nullptr) {
            sum += rchild->sum;
            color = color == rchild->color ? color : -1;
        }
    }

    void pushdown() {
        if (new_color == -1 || sum_delta == 0) return;

        if (lchild != nullptr) {
            if (sum_delta) {
                lchild->sum_delta += sum_delta;
                lchild->sum += sum_delta * (lchild->r - lchild->l + 1);
            }

            if (new_color != -1) {
                lchild->color = lchild->new_color = new_color;
            }
        }

        if (rchild != nullptr) {
            if (sum_delta) {
                rchild->sum_delta += sum_delta;
                rchild->sum += sum_delta * (rchild->r - rchild->l + 1);
            }

            if (new_color != -1) {
                rchild->color = rchild->new_color = new_color;
            }
        }

        new_color = -1;
        sum_delta = 0;
    }
};

void build(node *&u, int l, int r) {
    u = new node(l, r);

    if (l == r) {
        u->color = l;

        return;
    }

    int mid = (l + r) >> 1;

    if (l <= mid) build(u->lchild, l, mid);
    if (r > mid) build(u->rchild, mid + 1, r);

    u->pushup();
}

void modify(node *u, int l, int r, int new_color) {
    if (l <= u->l && u->r <= r && ~u->color) {
        u->sum += static_cast<long long>(std::abs(u->color - new_color)) * (u->r - u->l + 1);
        u->sum_delta += std::abs(u->color - new_color);
        u->color = u->new_color = new_color;

        return;
    }

    int mid = (u->l + u->r) >> 1;
    u->pushdown();

    if (l <= mid) modify(u->lchild, l, r, new_color);
    if (r > mid) modify(u->rchild, l, r, new_color);

    u->pushup();
}

long long query(node *u, int l, int r) {
    if (l <= u->l && u->r <= r) {
        return u->sum;
    }

    int mid = (u->l + u->r) >> 1;
    long long res = 0;

    u->pushdown();

    if (l <= mid) res += query(u->lchild, l, r);
    if (r > mid) res += query(u->rchild, l, r);

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    node *root;

    cin >> n >> m;

    build(root, 1, n);

    while (m--) {
        int op, l, r;

        cin >> op >> l >> r;

        if (op == 1) {
            int x;

            cin >> x;

            modify(root, l, r, x);
        } else {
            cout << query(root, l, r) << endl;
        }
    }

    delete root;

    return 0;
}
