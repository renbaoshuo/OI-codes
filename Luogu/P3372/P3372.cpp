#include <bits/stdc++.h>

using namespace std;

/**
 * 线段树节点
 */
struct node {
    int l, r;
    long long s, d;

    node() {
        l = r = s = d = 0;
    }

    node(int _l, int _r) {
        l = _l;
        r = _r;
        s = d = 0;
    }
} tr[100005 << 2];

int n, m, op, x, y, k, a[100005];

/**
 * 上传区间和
 * @param u 父节点下标
 */
void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

/**
 * 下放懒标记
 * @param u 父节点下标
 */
void pushdown(int u) {
    if (!tr[u].d) return;
    // 处理左子树
    tr[u << 1].d += tr[u].d;
    tr[u << 1].s += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].d;
    // 处理右子树
    tr[u << 1 | 1].d += tr[u].d;
    tr[u << 1 | 1].s += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].d;
    // 清除懒标记
    tr[u].d = 0;
}

/**
 * 建立线段树
 * @param u 根节点下标
 * @param l 左端点
 * @param r 右端点
 */
void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

/**
 * 修改区间
 * @param u 父节点下标
 * @param l 左端点
 * @param r 右端点
 * @param d 增加的值
 */
void modify(int u, int l, int r, int d) {
    if (tr[u].l >= l && tr[u].r <= r) {  // 被包含直接修改
        tr[u].d += d;
        tr[u].s += (tr[u].r - tr[u].l + 1) * d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);                               // 下放懒标记
    if (l <= mid) modify(u << 1, l, r, d);     // 和左侧有交集
    if (r > mid) modify(u << 1 | 1, l, r, d);  // 和右侧有交集
    pushup(u);                                 // 上传新信息
}

/**
 * 区间查询
 * @param u 父节点
 * @param l 左端点
 * @param r 右端点
 */
long long query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {  // 被包含直接返回
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    long long s = 0;
    pushdown(u);                                // 下放懒标记
    if (l <= mid) s += query(u << 1, l, r);     // 和左侧有交集
    if (r > mid) s += query(u << 1 | 1, l, r);  // 和右侧有交集
    return s;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        cin >> op >> x >> y;
        if (op == 1) {
            cin >> k;
            modify(1, x, y, k);
        } else if (op == 2) {
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}
