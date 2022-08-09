#include <iostream>
#include <cstring>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, a[N], c[N], ans[N];

inline int lowbit(int x) {
    return x & -x;
}

inline void add(int x, int y) {
    for (; x <= n; x += lowbit(x)) c[x] += y;
}

inline int sum(int x) {
    int ret = 0;
    for (; x > 0; x -= lowbit(x)) ret += c[x];
    return ret;
}

void solve(int l, int r, const std::vector<std::tuple<char, int, int, int, int>>& q) {
    if (q.empty()) return;

    if (r - l == 1) {
        for (const auto& x : q) {
            if (std::get<0>(x) == 'Q') {
                ans[std::get<4>(x)] = l;
            }
        }

        return;
    }

    int mid = l + r >> 1;
    std::vector<std::tuple<char, int, int, int, int>> left, right;

    for (const auto& e : q) {
        char op;
        int x, y, z, id;

        std::tie(op, x, y, z, id) = e;

        if (op == 'Q') {
            int k = sum(y) - sum(x - 1);

            if (k >= z) {
                left.push_back(e);
            } else {
                z -= k;
                right.emplace_back(op, x, y, z, id);
            }
        } else {  // op == 'C'
            if (y < mid) {
                add(x, z);
                left.push_back(e);
            } else {
                right.push_back(e);
            }
        }
    }

    for (const auto& e : left) {
        char op;
        int x, y, z, id;

        std::tie(op, x, y, z, id) = e;

        if (op == 'C') {
            add(x, -z);
        }
    }

    solve(l, mid, left);
    solve(mid, r, right);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(ans, 0xff, sizeof(ans));

    cin >> n >> m;

    std::vector<std::tuple<char, int, int, int, int>> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        q.emplace_back('C', i, a[i], 1, 0);
    }

    for (int i = 1; i <= m; i++) {
        char op;
        int x, y, z;

        cin >> op >> x >> y;

        if (op == 'Q') {
            cin >> z;

            q.emplace_back('Q', x, y, z, i);
        } else {  // op == 'C'
            q.emplace_back('C', x, a[x], -1, 0);
            a[x] = y;
            q.emplace_back('C', x, y, 1, 0);
        }
    }

    solve(0, 1e9, q);

    for (int i = 1; i <= m; i++) {
        if (~ans[i]) {
            cout << ans[i] << endl;
        }
    }

    return 0;
}
