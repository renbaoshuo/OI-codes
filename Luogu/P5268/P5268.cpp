#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, q, a[N], c1[N], c2[N], t, ans[N];
std::vector<std::tuple<int, int, int, int>> qs;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    t = sqrt(n);

    cin >> q;

    for (int i = 1, l1, r1, l2, r2; i <= q; i++) {
        cin >> l1 >> r1 >> l2 >> r2;

        qs.push_back(std::make_tuple(i, r1, r2, 1));
        qs.push_back(std::make_tuple(i, r1, l2 - 1, -1));
        qs.push_back(std::make_tuple(i, l1 - 1, r2, -1));
        qs.push_back(std::make_tuple(i, l1 - 1, l2 - 1, 1));
    }

    std::for_each(qs.begin(), qs.end(), [&](auto &x) {
        int &l = std::get<1>(x),
            &r = std::get<2>(x);

        if (l > r) std::swap(l, r);
    });

    std::sort(qs.begin(), qs.end(), [&](auto a, auto b) {
        int p = std::get<1>(a) / t,
            q = std::get<1>(b) / t;
        int x = std::get<2>(a),
            y = std::get<2>(b);

        return p == q ? p & 1 ? x < y : x > y : p < q;
    });

    int i = 0, j = 0, res = 0;
    for (auto &e : qs) {
        int id, l, r, x;
        std::tie(id, l, r, x) = e;

        while (i < r) res += c1[a[++i]], c2[a[i]]++;
        while (i > r) res -= c1[a[i]], c2[a[i--]]--;
        while (j < l) res += c2[a[++j]], c1[a[j]]++;
        while (j > l) res -= c2[a[j]], c1[a[j--]]--;

        ans[id] += x * res;
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
