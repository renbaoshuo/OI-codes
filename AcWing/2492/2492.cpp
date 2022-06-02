#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 50005,
          M = 200005,
          S = 1e6 + 5;

int n, m, a[N], c[S], t, ans[M];
std::vector<std::tuple<int, int, int>> q;

inline int get(int x) {
    return x / t;
}

inline void add(int x, int& r) {
    if (!c[x]++) r++;
}

inline void del(int x, int& r) {
    if (!--c[x]) r--;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    t = sqrt(n);

    cin >> m;

    for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r;

        q.push_back(std::make_tuple(i, l, r));
    }

    std::sort(q.begin(), q.end(), [&](auto a, auto b) {
        int p = get(std::get<1>(a)),
            q = get(std::get<1>(b));

        return p == q ? std::get<2>(a) < std::get<2>(b) : p < q;
    });

    for (int k = 0, i = 0, j = 1, res = 0, id, l, r; k < q.size(); k++) {
        std::tie(id, l, r) = q[k];

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
