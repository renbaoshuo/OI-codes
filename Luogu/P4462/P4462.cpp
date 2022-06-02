#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, k, a[N], c[N], t, ans[N];
std::vector<std::tuple<int, int, int>> q;

void add(int x, int &res) {
    c[x]++;
    res += c[x ^ k];
}

void del(int x, int &res) {
    c[x]--;
    res -= c[x ^ k];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        a[i] = a[i - 1] ^ a[i];
    }

    t = sqrt(n);

    for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r;

        q.push_back(std::make_tuple(i, l, r));
    }

    std::sort(q.begin(), q.end(), [&](auto a, auto b) {
        int p = std::get<1>(a) / t,
            q = std::get<1>(b) / t;
        int x = std::get<2>(a),
            y = std::get<2>(b);

        return p == q ? p & 1 ? x < y : x > y : p < q;
    });

    int i = 0, j = 1, res = 0;
    for (auto &e : q) {
        int id, l, r;
        std::tie(id, l, r) = e;

        while (i < r) add(a[++i], res);
        while (i > r) del(a[i--], res);
        while (j < l - 1) del(a[j++], res);
        while (j > l - 1) add(a[--j], res);

        ans[id] = res;
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
