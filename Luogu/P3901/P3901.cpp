#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, q, a[N], c[N], t;
bool ans[N];
std::vector<std::tuple<int, int, int>> qs;

inline void add(int x, int &res) {
    if (!c[x]++) res++;
}

inline void del(int x, int &res) {
    if (!--c[x]) res--;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    t = sqrt(n);

    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;

        qs.push_back(std::make_tuple(i, l, r));
    }

    std::sort(qs.begin(), qs.end(), [&](auto a, auto b) {
        int p = std::get<1>(a) / t,
            q = std::get<1>(b) / t;

        return p == q
                 ? (p & 1)
                     ? std::get<2>(a) < std::get<2>(b)
                     : std::get<2>(a) > std::get<2>(b)
                 : p < q;
    });

    int i = 0, j = 1, res = 0, x, l, r;
    for (auto q : qs) {
        std::tie(x, l, r) = q;

        while (i < r) add(a[++i], res);
        while (i > r) del(a[i--], res);
        while (j < l) del(a[j++], res);
        while (j > l) add(a[--j], res);

        ans[x] = res == (r - l + 1);
    }

    for (int i = 1; i <= q; i++) {
        cout << (ans[i] ? "Yes" : "No") << endl;
    }

    return 0;
}
