#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505,
          Q = 6e5 + 5;

int n, q, ans[Q], tr[N][N];
std::vector<std::tuple<int, int, int, int, int, int>> qs;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= n; j += lowbit(j)) {
            tr[i][j] += v;
        }
    }
}

int query(int x, int y) {
    int res = 0;

    for (int i = x; i; i -= lowbit(i)) {
        for (int j = y; j; j -= lowbit(j)) {
            res += tr[i][j];
        }
    }

    return res;
}

void solve(const std::vector<std::tuple<int, int, int, int, int, int>> &qs, long long l, long long r) {
    if (qs.empty()) return;

    if (l == r) {
        for (auto o : qs) {
            if (std::get<5>(o)) {
                ans[std::get<5>(o)] = l;
            }
        }

        return;
    }

    long long mid = l + r >> 1;
    std::vector<std::tuple<int, int, int, int, int, int>> ql, qr;

    for (auto o : qs) {
        int x, y, a, b, k, id;

        std::tie(x, y, a, b, k, id) = o;

        if (id) {
            int t = query(a, b) - query(x - 1, b) - query(a, y - 1) + query(x - 1, y - 1);

            if (t >= k) {
                ql.emplace_back(o);
            } else {
                qr.emplace_back(x, y, a, b, k - t, id);
            }
        } else {
            if (k <= mid) {
                add(x, y, 1);
                ql.emplace_back(o);
            } else {
                qr.emplace_back(o);
            }
        }
    }

    for (auto o : ql) {
        int x, y, k, id;

        std::tie(x, y, std::ignore, std::ignore, k, id) = o;

        if (!id && k <= mid) add(x, y, -1);
    }

    solve(ql, l, mid);
    solve(qr, mid + 1, r);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1, x; j <= n; j++) {
            cin >> x;

            qs.emplace_back(i, j, 0, 0, x, 0);
        }
    }

    for (int i = 1, x, y, a, b, k; i <= q; i++) {
        cin >> x >> y >> a >> b >> k;

        qs.emplace_back(x, y, a, b, k, i);
    }

    solve(qs, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
