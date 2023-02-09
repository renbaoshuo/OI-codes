#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits>
#include <random>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = 2e5 + 5;

int n, m, q, s[N], d[M];
std::mt19937 rng(std::random_device{}());
std::vector<std::pair<int, int>> g[N];
bool vis[N];

template <typename T>
class liner_base : private std::vector<T> {
  public:
    liner_base()
        : std::vector<T>(std::numeric_limits<T>::digits + 1, 0) {}

    bool insert(T w) {
        for (int i = std::numeric_limits<T>::digits; i >= 0; --i) {
            if (!(w >> i)) continue;

            if (!this->at(i)) {
                this->at(i) = w;

                return true;
            }

            w ^= this->at(i);
        }

        return false;
    }
};

void dfs(int u, int f) {
    vis[u] = true;

    for (auto e : g[u]) {
        int v = e.first,
            id = e.second;

        if (!vis[v]) {
            dfs(v, u);

            s[u] ^= s[v];
            d[id] ^= s[v];
        } else if (v != f && !d[id]) {
            d[id] = rng();

            s[u] ^= d[id];
            s[v] ^= d[id];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    dfs(1, 1);

    cin >> q;

    while (q--) {
        int c;
        liner_base<int> lb;
        bool ans = true;

        cin >> c;

        for (int i = 1, x; i <= c; i++) {
            cin >> x;

            ans &= lb.insert(d[x]);
        }

        cout << (ans ? "Connected" : "Disconnected") << endl;
    }

    return 0;
}
