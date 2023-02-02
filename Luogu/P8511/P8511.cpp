#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

int n, fa[N];
long long a[N], max, ans[N];
std::vector<int> g[N];
std::unordered_map<long long, int> lst;
bool vis[N];
int cnt = 1, tr[N * 60][2];

void insert(long long x) {
    int p = 1;

    for (int i = 60; i >= 0; i--) {
        bool ch = (x >> i) & 1;

        if (!tr[p][ch]) {
            tr[p][ch] = ++cnt;
        }

        p = tr[p][ch];
    }
}

long long query(long long x) {
    int p = 1;
    long long res = 0;

    for (int i = 60; i >= 0; i--) {
        int ch = (x >> i) & 1;

        if (!p) break;

        if (tr[p][ch ^ 1]) {
            res |= 1ll << i;
            p = tr[p][ch ^ 1];
        } else {
            p = tr[p][ch];
        }
    }

    return res;
}

void solve(int x) {
    max = 0;
    cnt = 1;
    memset(tr, 0x00, sizeof(tr));
    std::vector<int> vec;
    std::vector<bool> vis2(n + 1);

    for (int i = x; i; i = fa[i]) {
        vec.emplace_back(i);
        vis[i] = true;
        vis2[i] = true;
    }

    std::reverse(vec.begin(), vec.end());

    std::function<void(int)> get = [&](int u) -> void {
        insert(a[u]);
        max = std::max(max, query(a[u]));

        for (int v : g[u]) {
            get(v);
        }
    };

    for (int u : vec) {
        ans[u] = max;

        for (int v : g[u]) {
            if (vis2[v]) continue;

            get(v);
        }

        insert(a[u]);
        max = std::max(max, query(a[u]));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> fa[i];

        g[fa[i]].emplace_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        max = std::max(max, query(a[i]));
        insert(a[i]);
    }

    int x = 1, y = 1;

    for (int i = 1; i <= n; i++) {
        lst[a[i]] = i;

        if (lst.count(a[i] ^ max)) {
            x = i;
            y = lst[a[i] ^ max];

            break;
        }
    }

    solve(x);
    solve(y);

    for (int i = 1; i <= n; i++) {
        cout << (vis[i] ? ans[i] : max) << endl;
    }

    return 0;
}
