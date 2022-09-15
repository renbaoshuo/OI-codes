#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, m, w[N], c[N], c1[N], c2[N], t;
std::pair<int, int> now, ans[N];
std::vector<std::tuple<int, int, int, int, int>> q;

inline int lowbit(int x) {
    return x & -x;
}

void add(int *c, int x, int y) {
    for (; x <= n; x += lowbit(x)) c[x] += y;
}

int sum(int *c, int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}

void add(int x) {
    if (!c[x]++) add(c1, x, 1);
    add(c2, x, 1);
}

void del(int x) {
    if (!--c[x]) add(c1, x, -1);
    add(c2, x, -1);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    t = sqrt(n);

    for (int i = 1, l, r, a, b; i <= m; i++) {
        cin >> l >> r >> a >> b;

        q.push_back(std::make_tuple(i, l, r, a, b));
    }

    std::sort(q.begin(), q.end(), [&](auto a, auto b) {
        int p = std::get<1>(a) / t,
            q = std::get<1>(b) / t;
        int x = std::get<2>(a),
            y = std::get<2>(b);

        return p == q
                 ? p & 1 ? x < y : x > y
                 : p < q;
    });

    int i = 0, j = 1;
    for (auto &e : q) {
        int id, l, r, a, b;
        std::tie(id, l, r, a, b) = e;

        while (i < r) add(w[++i]);
        while (i > r) del(w[i--]);
        while (j < l) del(w[j++]);
        while (j > l) add(w[--j]);

        ans[id] = std::make_pair(sum(c2, b) - sum(c2, a - 1), sum(c1, b) - sum(c1, a - 1));
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }

    return 0;
}
