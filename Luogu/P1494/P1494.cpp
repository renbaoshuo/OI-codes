#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 50005;

int n, m, a[N], c[N], t;
std::pair<long long, long long> now, ans[N];
std::vector<std::tuple<int, int, int>> q;

void add(int x) {
    if (++c[x] > 1) {
        now.first += c[x] * (c[x] - 1) - (c[x] - 1) * (c[x] - 2);
    }
}

void del(int x) {
    if (--c[x]) {
        now.first += c[x] * (c[x] - 1) - (c[x] + 1) * c[x];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    t = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r;

        q.push_back(std::make_tuple(i, l, r));
    }

    std::sort(q.begin(), q.end(), [&](auto a, auto b) {
        int p = std::get<1>(a) / t,
            q = std::get<1>(b) / t;

        return p == q ? std::get<2>(a) < std::get<2>(b) : p < q;
    });

    int i = 0, j = 1, x, l, r;
    for (auto e : q) {
        std::tie(x, l, r) = e;

        if (l == r) {
            ans[x] = std::make_pair(0, 1);
        } else {
            while (i < r) add(a[++i]);
            while (i > r) del(a[i--]);
            while (j < l) del(a[j++]);
            while (j > l) add(a[--j]);

            now.second = 1ll * (r - l + 1) * (r - l);
            int g = std::__gcd(now.first, now.second);
            ans[x] = std::make_pair(now.first / g, now.second / g);
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i].first << '/' << ans[i].second << endl;
    }

    return 0;
}
