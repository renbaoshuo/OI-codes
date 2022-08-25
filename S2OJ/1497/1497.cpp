#include <iostream>
#include <chrono>
#include <map>
#include <random>
#include <set>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, m, a, b, ans;
unsigned long long sum[N];
std::vector<std::pair<int, unsigned long long>> g[N];
std::map<int, unsigned long long> map;
std::set<unsigned long long> set;

void dfs(int u, int f, unsigned long long s) {
    sum[u] = sum[f] ^ s;

    for (auto e : g[u]) {
        int v = e.first;
        unsigned long long w = e.second;

        if (v == f) continue;

        dfs(v, u, w);
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::mt19937_64 rand(std::chrono::system_clock::now().time_since_epoch().count());

    cin >> n >> m;

    for (int i = 1; i < n; i++) {
        int u, v, w;

        cin >> u >> v >> w;

        if (!map.count(w)) map[w] = rand();
        set.insert(map[w]);
        g[u].emplace_back(v, map[w]);
        g[v].emplace_back(u, map[w]);
    }

    dfs(1, 0, 0);

    cin >> a >> b;

    while (m--) {
        int x = a % n + 1,
            y = b % n + 1;

        unsigned long long s = sum[x] ^ sum[y];

        if (s == 0 || set.count(s)) ans++;

        a = static_cast<long long>(a) * 666073 % 1000000007;
        b = static_cast<long long>(b) * 233 % 998244353;
    }

    cout << ans << endl;

    return 0;
}
