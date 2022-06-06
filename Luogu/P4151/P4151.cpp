#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 50005;

int n, m;
bool vis[N];
unsigned long long p[N], dep[N], ans;
std::vector<std::pair<int, unsigned long long>> g[N];

inline void insert(unsigned long long x) {
    for (int i = 60; ~i; i--) {
        if (x & (1ull << i)) {
            if (p[i]) {
                x ^= p[i];
            } else {
                p[i] = x;
                return;
            }
        }
    }
}

void dfs(int u, unsigned long long sum) {
    vis[u] = true;
    dep[u] = sum;

    for (auto e : g[u]) {
        int v = e.first;
        unsigned long long w = e.second;

        if (vis[v]) insert(sum ^ dep[v] ^ w);
        else dfs(v, sum ^ w);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int s, t;
        unsigned long long d;

        cin >> s >> t >> d;

        g[s].push_back(std::make_pair(t, d));
        g[t].push_back(std::make_pair(s, d));
    }

    dfs(1, 0);

    ans = dep[n];

    for (int i = 60; ~i; i--) {
        if ((ans ^ p[i]) > ans) ans ^= p[i];
    }

    cout << ans << endl;

    return 0;
}
