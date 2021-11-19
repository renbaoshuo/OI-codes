#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    long long s, d, x;

    node() {
        l = r = s = d = 0;
        x = 1;
    }
    node(int _l, int _r) {
        l = _l, r = _r;
        s = d = 0;
        x = 1;
    }
} tr[100005 << 2];
int n, m, p, op, x, y;
long long k, a[100005];

/**
 * @brief 上传信息
 * @param u 父节点下标
 */
void pushup(int u) {
    tr[u].s = (tr[u << 1].s + tr[u << 1 | 1].s) % p;
}

/**
 * @brief 下放懒标记
 * @param u 父节点下标
 * @attention 先乘后加
 */
void pushdown(int u) {
    // 左子树
    tr[u << 1].s = ((tr[u << 1].s * tr[u].x) + (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].d) % p;
    tr[u << 1].x = tr[u << 1].x * tr[u].x % p;
    tr[u << 1].d = (tr[u << 1].d * tr[u].x + tr[u].d) % p;
    // 右子树
    tr[u << 1 | 1].s = ((tr[u << 1 | 1].s * tr[u].x) + (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].d) % p;
    tr[u << 1 | 1].x = tr[u << 1 | 1].x * tr[u].x % p;
    tr[u << 1 | 1].d = (tr[u << 1 | 1].d * tr[u].x + tr[u].d) % p;
    // 清除懒标记
    tr[u].d = 0;
    tr[u].x = 1;
}

/**
 * @brief 建立线段树
 * @param u 根节点下标
 * @param l 左端点
 * @param r 右端点
 */
void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = a[l] % p;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

/**
 * @brief 区间加
 * @details 将区间 [l, r] 中的每一个数加上 d
 * @param u 父节点下标
 * @param l 左端点
 * @param r 右端点
 * @param x 乘上的数
 * @param d 增加的值
 */
void modify(int u, int l, int r, long long x, long long d) {
    // 被包含直接修改
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].s = ((tr[u].s * x) + (tr[u].r - tr[u].l + 1) * d) % p;
        tr[u].x = tr[u].x * x % p;
        tr[u].d = (tr[u].d * x + d) % p;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);                                  // 下放懒标记
    if (l <= mid) modify(u << 1, l, r, x, d);     // 和左侧有交集
    if (r > mid) modify(u << 1 | 1, l, r, x, d);  // 和右侧有交集
    pushup(u);                                    // 上传新信息
}

/**
 * @brief 求区间和
 * @param u 
 * @param l 
 * @param r 
 * @return int 
 */
long long query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {  // 被包含直接返回
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    long long s = 0;
    pushdown(u);                                         // 下放懒标记
    if (l <= mid) s = query(u << 1, l, r);               // 和左侧有交集
    if (r > mid) s = (s + query(u << 1 | 1, l, r)) % p;  // 和右侧有交集
    return s;
}

signed main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        cin >> op >> x >> y;
        if (op == 1) {
            cin >> k;
            modify(1, x, y, k, 0);
        } else if (op == 2) {
            cin >> k;
            modify(1, x, y, 1, k);
        } else if (op == 3) {
            cout << query(1, x, y) % p << endl;
        }
    }
    return 0;
}
