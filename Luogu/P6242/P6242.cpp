#include <iostream>
#include <functional>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, a[N];

struct node {
    int l, r;  // 左右端点

    int tag_add;          // 懒标记：加减标记（最大值无关）
    int tag_his_add;      // 懒标记：历史最大的加减标记（最大值无关）
    int tag_add_max;      // 懒标记：最大值的加减标记
    int tag_his_add_max;  // 懒标记：历史最大的最大值的加减标记

    long long sum;  // 区间和
    int max;        // 区间最大值
    int max_2nd;    // 区间严格次大值
    int his_max;    // 历史区间最大值
    int max_cnt;    // 区间最大值个数

    node(const int &_l = 0, const int &_r = 0)
        : l(_l),
          r(_r),
          tag_add(0),
          tag_his_add(0),
          tag_add_max(0),
          tag_his_add_max(0),
          sum(0),
          max(0),
          max_2nd(-INF),  // -INF 表示不存在
          his_max(0),
          max_cnt(1) {}
} tr[N << 2];

void pushup(int u) {
    auto &p = tr[u],
         &l = tr[u << 1],
         &r = tr[u << 1 | 1];

    p.sum = l.sum + r.sum;
    p.his_max = std::max(l.his_max, r.his_max);

    if (l.max == r.max) {
        p.max = l.max;
        p.max_2nd = std::max(l.max_2nd, r.max_2nd);
        p.max_cnt = l.max_cnt + r.max_cnt;
    } else if (l.max > r.max) {
        p.max = l.max;
        p.max_2nd = std::max(l.max_2nd, r.max);
        p.max_cnt = l.max_cnt;
    } else {  // l.max < r.max
        p.max = r.max;
        p.max_2nd = std::max(l.max, r.max_2nd);
        p.max_cnt = r.max_cnt;
    }
}

void pushdown(int u) {
    auto &p = tr[u];

    std::function<void(node &)> update = [&](node &ch) -> void {
        ch.sum += static_cast<long long>(ch.r - ch.l + 1) * p.tag_add;

        ch.his_max = std::max(ch.his_max, ch.max + p.tag_his_add);
        ch.max += p.tag_add;

        if (ch.max_2nd != -INF) ch.max_2nd += p.tag_add;

        ch.tag_his_add = std::max(ch.tag_his_add, ch.tag_add + p.tag_his_add);
        ch.tag_add += p.tag_add;

        ch.tag_his_add_max = std::max(ch.tag_his_add_max, ch.tag_add_max + p.tag_his_add);
        ch.tag_add_max += p.tag_add;
    };

    std::function<void(node &)> update_with_max = [&](node &ch) -> void {
        // 最大值相关部分
        ch.sum += static_cast<long long>(ch.max_cnt) * p.tag_add_max;

        ch.his_max = std::max(ch.his_max, ch.max + p.tag_his_add_max);
        ch.max += p.tag_add_max;

        ch.tag_his_add_max = std::max(ch.tag_his_add_max, ch.tag_add_max + p.tag_his_add_max);
        ch.tag_add_max += p.tag_add_max;

        // 最大值无关部分
        ch.sum += static_cast<long long>(ch.r - ch.l + 1 - ch.max_cnt) * p.tag_add;

        ch.tag_his_add = std::max(ch.tag_his_add, ch.tag_add + p.tag_his_add);
        ch.tag_add += p.tag_add;

        if (ch.max_2nd != -INF) ch.max_2nd += p.tag_add;
    };

    if (tr[u << 1].max == tr[u << 1 | 1].max) {
        update_with_max(tr[u << 1]);      // 左子树：最大值相关
        update_with_max(tr[u << 1 | 1]);  // 右子树：最大值相关
    } else if (tr[u << 1].max > tr[u << 1 | 1].max) {
        update_with_max(tr[u << 1]);  // 左子树：最大值相关
        update(tr[u << 1 | 1]);       // 右子树：最大值无关
    } else {
        update(tr[u << 1]);               // 左子树：最大值无关
        update_with_max(tr[u << 1 | 1]);  // 右子树：最大值相关
    }

    p.tag_add = p.tag_add_max = p.tag_his_add = p.tag_his_add_max = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) {
        tr[u].sum = tr[u].max = tr[u].his_max = a[l];

        return;
    }

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(u);
}

/**
 * 对于所有的 i ∈ [l, r]，将 a[i] 加上 k
 */
void modify_add(int u, int l, int r, int k) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].sum += static_cast<long long>(k) * (tr[u].r - tr[u].l + 1);

        tr[u].max += k;
        tr[u].his_max = std::max(tr[u].his_max, tr[u].max);
        if (tr[u].max_2nd != -INF) tr[u].max_2nd += k;

        tr[u].tag_add += k;
        tr[u].tag_his_add = std::max(tr[u].tag_his_add, tr[u].tag_add);

        tr[u].tag_add_max += k;
        tr[u].tag_his_add_max = std::max(tr[u].tag_his_add_max, tr[u].tag_add_max);

        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    pushdown(u);

    if (l <= mid) modify_add(u << 1, l, r, k);
    if (r > mid) modify_add(u << 1 | 1, l, r, k);

    pushup(u);
}

/**
 * 对于所有的 i ∈ [l, r]，将 a[i] 变为 min(a[i], v)
 */
void modify_min(int u, int l, int r, int v) {
    if (tr[u].max <= v) return;

    if (l <= tr[u].l && tr[u].r <= r && tr[u].max_2nd < v) {
        int t = v - tr[u].max;

        tr[u].sum += static_cast<long long>(t) * tr[u].max_cnt;

        tr[u].max += t;
        tr[u].his_max = std::max(tr[u].his_max, tr[u].max);

        tr[u].tag_add_max += t;
        tr[u].tag_his_add_max = std::max(tr[u].tag_his_add_max, tr[u].tag_add_max);

        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    pushdown(u);

    if (l <= mid) modify_min(u << 1, l, r, v);
    if (r > mid) modify_min(u << 1 | 1, l, r, v);

    pushup(u);
}

/**
 * 求满足 i ∈ [l, r] 的所有 a[i] 的和
 */
long long query_sum(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;

    int mid = (tr[u].l + tr[u].r) >> 1;
    long long res = 0;

    pushdown(u);

    if (l <= mid) res += query_sum(u << 1, l, r);
    if (r > mid) res += query_sum(u << 1 | 1, l, r);

    return res;
}

/**
 * 求满足 i ∈ [l, r] 的所有 a[i] 的最大值
 */
int query_max(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].max;

    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = -INF;

    pushdown(u);

    if (l <= mid) res = std::max(res, query_max(u << 1, l, r));
    if (r > mid) res = std::max(res, query_max(u << 1 | 1, l, r));

    return res;
}

/**
 * 求满足 i ∈ [l, r] 的所有 a[i] 的历史最大值
 */
int query_his_max(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].his_max;

    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = -INF;

    pushdown(u);

    if (l <= mid) res = std::max(res, query_his_max(u << 1, l, r));
    if (r > mid) res = std::max(res, query_his_max(u << 1 | 1, l, r));

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int l, r, k;

            cin >> l >> r >> k;

            modify_add(1, l, r, k);
        } else if (op == 2) {
            int l, r, v;

            cin >> l >> r >> v;

            modify_min(1, l, r, v);
        } else if (op == 3) {
            int l, r;

            cin >> l >> r;

            cout << query_sum(1, l, r) << endl;
        } else if (op == 4) {
            int l, r;

            cin >> l >> r;

            cout << query_max(1, l, r) << endl;
        } else {  // op == 5
            int l, r;

            cin >> l >> r;

            cout << query_his_max(1, l, r) << endl;
        }
    }

    return 0;
}
