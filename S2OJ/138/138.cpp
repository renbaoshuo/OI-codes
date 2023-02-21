#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;
const int mod = 998244353;

int n, m, fa[N << 1], s[N << 1];

constexpr int binpow(int a, int b, int mod = ::mod) {
    int res = 1;

    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % mod;
        a = static_cast<long long>(a) * a % mod;
        b >>= 1;
    }

    return res;
}

int find(int x) {
    return fa[x] == x ? x : find(fa[x]);
}

int query(int x) {
    int res = binpow(3, n);

    while (fa[x] != x) {
        res = static_cast<long long>(res) * s[x] % mod;
        x = fa[x];
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    std::iota(std::begin(fa), std::end(fa), 0);
    std::fill(std::begin(s), std::end(s), 1);

    for (int i = 1, op; i <= m; i++) {
        cin >> op;

        if (op == 1) {
            int u, v;

            cin >> u >> v;

            int x = find(u),
                y = find(v);

            s[x] = 2 * binpow(3, mod - 2) % mod;
            s[y] = binpow(3, mod - 2) % mod;
            fa[x] = n + i;
            fa[y] = n + i;
        } else {  // op == 2
            int u;

            cin >> u;

            cout << query(u) << endl;
        }
    }

    return 0;
}
