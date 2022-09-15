#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5;

int n, m, k, a[N], c[N], t, ans[N];
std::vector<std::tuple<int, int, int>> q;

inline void add(int x, int &res) {
    res += 2 * c[x] + 1;
    c[x]++;
}

inline void del(int x, int &res) {
    res -= 2 * c[x] - 1;
    c[x]--;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    t = sqrt(n);

    for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r;

        q.push_back(std::make_tuple(i, l, r));
    }

    std::sort(q.begin(), q.end(), [&](auto a, auto b) {
        int p = std::get<1>(a) / t,
            q = std::get<1>(b) / t;

        return p == q
                 ? (p & 1)
                     ? std::get<2>(a) < std::get<2>(b)
                     : std::get<2>(a) > std::get<2>(b)
                 : p < q;
    });

    int i = 0, j = 1, res = 0, id, l, r;
    for (auto &e : q) {
        std::tie(id, l, r) = e;

        while (i < r) add(a[++i], res);
        while (i > r) del(a[i--], res);
        while (j < l) del(a[j++], res);
        while (j > l) add(a[--j], res);

        ans[id] = res;
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
