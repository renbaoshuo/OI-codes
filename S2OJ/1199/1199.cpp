#include <iostream>
#include <limits>
#include <stack>

using std::cin;
using std::cout;
using std::endl;

// Limits
const int N = 300005;

// Variables
int a[N];
bool vis[N];

// Segment Tree
void build(int, int, int);
int query(int, int, int);

int main() {
    std::ios::sync_with_stdio(false);

    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    a[0] = std::numeric_limits<int>::max();
    build(1, 1, n);

    int pos = query(1, 1, c);
    std::stack<int> st;

    for (int i = 1; i < pos; i++) {
        st.push(i);
    }
    cout << a[pos] << ' ';

    for (int i = c + 1; i <= n; i++) {
        int p = query(1, pos + 1, i);
        if (!st.empty() && a[st.top()] <= a[p]) {
            cout << a[st.top()] << ' ';
            st.pop();
        } else {
            for (int j = pos + 1; j < p; j++) {
                st.push(j);
            }
            pos = p;
            cout << a[p] << ' ';
        }
    }

    for (int i = 1; i < c; i++) {
        int p = pos + 1 <= n ? query(1, pos + 1, n) : 0;
        if (!st.empty() && a[st.top()] <= a[p]) {
            cout << a[st.top()] << ' ';
            st.pop();
        } else {
            for (int j = pos + 1; j < p; j++) {
                st.push(j);
            }
            pos = p;
            cout << a[p] << ' ';
        }
    }

    cout << endl;

    return 0;
}

// === Segment Tree ===

struct node {
    int l, r, id;

    node()
        : l(0),
          r(0),
          id(0) {}

    node(int _l, int _r)
        : l(_l),
          r(_r),
          id(0) {}
} tr[N << 2];

inline void pushup(int u) {
    tr[u].id = a[tr[u << 1].id] <= a[tr[u << 1 | 1].id] ? tr[u << 1].id : tr[u << 1 | 1].id;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].id = l;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

/**
 * 查询区间 [l, r] 最小值，并返回最小值在 a 数组中对应的**下标**
 * @param u 根节点坐标
 * @param l 区间左端点
 * @param r 区间右端点
 * @return 最小值在 a 数组中对应的**下标**
 */
int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].id;
    int mid = tr[u].l + tr[u].r >> 1,
        pos = 0;
    if (l <= mid) {
        int t = query(u << 1, l, r);
        if (a[t] < a[pos]) pos = t;
    }
    if (r > mid) {
        int t = query(u << 1 | 1, l, r);
        if (a[t] < a[pos]) pos = t;
    }
    return pos;
}
