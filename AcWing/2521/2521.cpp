#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 10005,
          M = 1e6 + 5;

int n, m, a[N], cnt[M], t, ans[N];
std::vector<std::pair<int, int>> c;
std::vector<std::tuple<int, int, int, int>> q;

inline void add(int x, int &res) {
    if (!cnt[x]++) res++;
}

inline void del(int x, int &res) {
    if (!--cnt[x]) res--;
}

inline void tim(int x, int i, int j, int &res) {
    if (j <= c[x].first && c[x].first <= i) {
        del(a[c[x].first], res);
        add(c[x].second, res);
    }

    std::swap(a[c[x].first], c[x].second);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    c.push_back(std::make_pair(0, 0));

    for (int i = 1; i <= m; i++) {
        char op;
        int x, y;
        cin >> op >> x >> y;

        if (op == 'Q') {
            q.push_back(std::make_tuple(i, x, y, c.size() - 1));
        } else {  // op == 'C'
            c.push_back(std::make_pair(x, y));
        }
    }

    t = cbrt(n * std::max(1, (int)c.size())) + 1;
    std::sort(q.begin(), q.end(), [&](auto a, auto b) {
        int p = std::get<1>(a) / t,
            q = std::get<1>(b) / t;
        int x = std::get<2>(a) / t,
            y = std::get<2>(b) / t;

        return p == q
                 ? x == y ? std::get<3>(a) < std::get<3>(b) : x < y
                 : p < q;
    });

    int i = 0, j = 1, now = 0, res = 0;
    for (auto &e : q) {
        int id, l, r, t2;

        std::tie(id, l, r, t2) = e;

        while (i < r) add(a[++i], res);
        while (i > r) del(a[i--], res);
        while (j < l) del(a[j++], res);
        while (j > l) add(a[--j], res);
        while (now < t2) tim(++now, i, j, res);
        while (now > t2) tim(now--, i, j, res);

        ans[id] = res;
    }

    std::sort(q.begin(), q.end(), [&](auto a, auto b) {
        return std::get<0>(a) < std::get<0>(b);
    });

    for (auto &e : q) {
        cout << ans[std::get<0>(e)] << endl;
    }

    return 0;
}
