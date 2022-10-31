#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, q, t, a[N], cnt[N], cnt2[N], ans[N];
std::tuple<int, int, int, int> queries[N];

void add(int x) {
    cnt2[++cnt[x]]++;
}

void del(int x) {
    cnt2[cnt[x]--]--;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> q;

    for (int i = 1; i <= q; i++) {
        cin >> std::get<1>(queries[i]) >> std::get<2>(queries[i]) >> std::get<3>(queries[i]);
        std::get<0>(queries[i]) = i;
    }

    t = std::sqrt(q);
    std::sort(queries + 1, queries + 1 + q, [&](auto a, auto b) -> bool {
        int p = std::get<1>(a) / t,
            q = std::get<1>(b) / t;

        return p == q
                 ? (p & 1)
                     ? std::get<2>(a) < std::get<2>(b)
                     : std::get<2>(a) > std::get<2>(b)
                 : p < q;
    });

    cnt2[0] = n;
    for (int _ = 1, i = 0, j = 1; _ <= q; _++) {
        int id, l, r, k;

        std::tie(id, l, r, k) = queries[_];

        while (i < r) add(a[++i]);
        while (i > r) del(a[i--]);
        while (j > l) add(a[--j]);
        while (j < l) del(a[j++]);

        ans[id] = cnt2[k];
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
