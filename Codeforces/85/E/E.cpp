#include <iostream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e4 + 5;
const int mod = 1e9 + 7;

int n, color[N], ans;
std::pair<int, int> points[N];

int dis(int i, int j) {
    return std::abs(points[i].first - points[j].first) + std::abs(points[i].second - points[j].second);
}

bool dfs(int u, int c, int limit) {
    color[u] = c;

    for (int v = 1; v <= n; v++) {
        if (v == u || dis(u, v) <= limit) continue;

        if (color[v] == -1) {
            if (!dfs(v, c ^ 1, limit)) return false;
        } else if (color[v] == color[u]) {
            return false;
        }
    }

    return true;
}

bool check(int x) {
    std::fill(std::begin(color), std::end(color), -1);

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            cnt++;
            if (!dfs(i, 1, x)) return false;
        }
    }

    ans = cnt;

    return true;
}

int binpow(int a, int b) {
    int res = 1;

    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % mod;
        a = static_cast<long long>(a) * a % mod;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    int l = 0,
        r = 10000,
        res = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << res << endl
         << binpow(2, ans) << endl;

    return 0;
}
