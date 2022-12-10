#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 4e6 + 5;

int n, m, q;

template <typename T>
class array {
  private:
    T data[N << 2];

  public:
    array() {
        std::fill(std::begin(data), std::end(data), 0);
    }

    T* operator[](int x) {
        return data + x * m;
    }
};

array<bool> g;
array<int> up, down, sum;

void pushup(int u, int ls, int rs, int l, int r) {
    std::deque<int> q1, q2;

    for (int i = 1, j = 1; i <= m; i++) {
        while (!q1.empty() && down[ls][i] < down[ls][q1.back()]) q1.pop_back();
        while (!q2.empty() && up[rs][i] < up[rs][q2.back()]) q2.pop_back();

        q1.emplace_back(i);
        q2.emplace_back(i);

        while (j <= i && i - j + 1 > up[rs][q2.front()] + down[ls][q1.front()]) {
            j++;

            if (q1.front() < j) q1.pop_front();
            if (q2.front() < j) q2.pop_front();
        }

        sum[u][i] = std::max({sum[ls][i], sum[rs][i], i - j + 1});
    }

    for (int i = 1; i <= m; i++) {
        up[u][i] = up[ls][i] + (up[ls][i] == l ? up[rs][i] : 0);
        down[u][i] = down[rs][i] + (down[rs][i] == r ? down[ls][i] : 0);
    }
}

void build(int u, int l, int r) {
    if (l == r) {
        for (int i = 1; i <= m; i++) {
            up[u][i] = down[u][i] = sum[u][i] = g[l][i];
        }

        return;
    }

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(u, u << 1, u << 1 | 1, mid - l + 1, r - mid);
}

void modify(int u, int l, int r, int p, int y) {
    if (l == r) {
        up[u][y] = down[u][y] = sum[u][y] = g[p][y] ^= 1;

        return;
    }

    int mid = (l + r) >> 1;

    if (p <= mid) modify(u << 1, l, mid, p, y);
    else modify(u << 1 | 1, mid + 1, r, p, y);

    pushup(u, u << 1, u << 1 | 1, mid - l + 1, r - mid);
}

void query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        pushup(0, 0, u, l - ql, r - l + 1);

        return;
    }

    int mid = (l + r) >> 1;

    if (ql <= mid) query(u << 1, l, mid, ql, qr);
    if (qr > mid) query(u << 1 | 1, mid + 1, r, ql, qr);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    build(1, 1, n);

    while (q--) {
        int op;

        cin >> op;

        if (op == 0) {
            int x, y;

            cin >> x >> y;

            modify(1, 1, n, x, y);
        } else {  // op == 1
            int l, s, r, t, ans = 0;

            cin >> l >> s >> r >> t;

            for (int i = 1; i <= m; i++) {
                up[0][i] = down[0][i] = sum[0][i] = 0;
            }

            query(1, 1, n, l, r);

            for (int i = s; i <= t; i++) {
                ans = std::max(ans, std::min(sum[0][i], i - s + 1));
            }

            cout << ans << endl;
        }
    }

    return 0;
}
