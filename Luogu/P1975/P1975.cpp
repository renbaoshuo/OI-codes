#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e4 + 5;

int n, m, h[N], ans;
std::vector<int> nums;

class SegmentTree {
  private:
    struct node {
        int l, r;
        int sum;

        node *lchild, *rchild;

        node(const int &_l = 0, const int &_r = 0)
            : l(_l), r(_r), sum(0), lchild(nullptr), rchild(nullptr) {}

        void pushup() {
            sum = 0;

            if (lchild != nullptr) sum += lchild->sum;
            if (rchild != nullptr) sum += rchild->sum;
        }
    };

    node *root;

    void modify(node *&cur, int l, int r, int pos, int val) {
        if (cur == nullptr) cur = new node(l, r);

        if (l == r) {
            cur->sum += val;

            return;
        }

        int mid = l + r >> 1;

        if (pos <= mid) modify(cur->lchild, l, mid, pos, val);
        else modify(cur->rchild, mid + 1, r, pos, val);

        cur->pushup();
    }

    int query(node *cur, int l, int r, int ql, int qr) {
        if (cur == nullptr) return 0;
        if (ql <= l && r <= qr) return cur->sum;

        int mid = l + r >> 1,
            res = 0;

        if (ql <= mid) res += query(cur->lchild, l, mid, ql, qr);
        if (qr > mid) res += query(cur->rchild, mid + 1, r, ql, qr);

        return res;
    }

  public:
    SegmentTree()
        : root(nullptr) {}

    void modify(int pos, int val) {
        modify(root, 1, n, pos, val);
    }

    int query(int ql, int qr) {
        return query(root, 1, n, ql, qr);
    }
} tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y, int z) {
    for (; x <= n; x += lowbit(x)) tr[x].modify(y, z);
}

int sum(int x, int l, int r) {
    int res = 0;

    for (; x; x -= lowbit(x)) res += tr[x].query(l, r);

    return res;
}

int get(int x) {
    return sum(x - 1, h[x] + 1, n) + sum(n, 1, h[x] - 1) - sum(x - 1, 1, h[x] - 1);
}

int find(int x) {
    return std::lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];

        nums.emplace_back(h[i]);
    }

    std::sort(nums.begin(), nums.end());
    std::transform(h + 1, h + 1 + n, h + 1, find);

    for (int i = 1; i <= n; i++) {
        add(i, h[i], 1);
        ans += sum(i - 1, h[i] + 1, n);
    }

    cout << ans << endl;

    cin >> m;

    while (m--) {
        int x, y;

        cin >> x >> y;

        if (x > y) std::swap(x, y);
        if (h[x] > h[y]) ans++;

        ans -= get(x) + get(y);
        add(x, h[x], -1);
        add(y, h[y], -1);
        std::swap(h[x], h[y]);
        if (h[x] > h[y]) ans--;
        add(x, h[x], 1);
        add(y, h[y], 1);
        ans += get(x) + get(y);

        cout << ans << endl;
    }

    return 0;
}
