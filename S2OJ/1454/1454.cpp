#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, m, q, p[N], s[N], c[N], ans[N];
std::vector<int> g[N];
std::vector<std::pair<int, int>> qs[N];

int binpow(int a, int b) {
    int res = 1;
    a %= mod;

    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % mod;
        a = static_cast<long long>(a) * a % mod;
        b >>= 1;
    }

    return res;
}

inline int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (; x; x -= lowbit(x)) c[x] = (c[x] + y) % mod;
}

int sum(int x) {
    int res = 0;
    for (; x <= n; x += lowbit(x)) res = (res + c[x]) % mod;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;

        p[i] = static_cast<long long>(a) * binpow(b, mod - 2) % mod;
        s[i] = (s[i - 1] + p[i]) % mod;
    }

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        if (u > v) std::swap(u, v);

        g[v].push_back(u);
    }

    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;

        ans[i] = (s[r] - s[l - 1]) % mod;
        qs[r].emplace_back(i, l);
    }

    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            add(v, static_cast<long long>(p[i]) * p[v] % mod);
        }

        for (auto t : qs[i]) {
            ans[t.first] = (ans[t.first] - sum(t.second)) % mod;
        }
    }

    for (int i = 1; i <= q; i++) {
        cout << (static_cast<long long>(ans[i]) % mod + mod) % mod << endl;
    }

    return 0;
}
