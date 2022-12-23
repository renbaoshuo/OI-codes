#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 6e4 + 5;

int n, m, t, a[N], cnt[1 << 26], res, ans[N];
std::string s;
std::vector<std::tuple<int, int, int>> qs;

void add(int x) {
    res += cnt[a[x]]++;

    for (int i = 0; i < 26; i++) {
        res += cnt[a[x] ^ (1 << i)];
    }
}

void del(int x) {
    res -= --cnt[a[x]];

    for (int i = 0; i < 26; i++) {
        res -= cnt[a[x] ^ (1 << i)];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;

    s = ' ' + s;

    for (int i = 1; i <= n; i++) {
        a[i + 1] = a[i] ^ (1 << (s[i] - 'a'));
    }

    for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r;

        qs.emplace_back(i, l, r + 1);
    }

    t = std::sqrt(n + 1);

    std::sort(qs.begin(), qs.end(), [&](std::tuple<int, int, int> lhs, std::tuple<int, int, int> rhs) -> bool {
        int p = std::get<1>(lhs) / t,
            q = std::get<1>(rhs) / t;
        int x = std::get<2>(lhs),
            y = std::get<2>(rhs);

        return p == q
                 ? p & 1 ? x < y : x > y
                 : p < q;
    });

    int i = 0, j = 1;

    for (auto q : qs) {
        int id, l, r;

        std::tie(id, l, r) = q;

        while (i < r) add(++i);
        while (i > r) del(i--);
        while (j < l) del(j++);
        while (j > l) add(--j);

        ans[id] = res;
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
