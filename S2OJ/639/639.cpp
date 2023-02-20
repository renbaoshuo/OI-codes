#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5,
          M = 62;
const int mod = 998244353;

int n, a[N], pre[N][M], suf[N][M], f1[M][M], f2[M][M], same, ans;
std::string s;

int c2(int x) {
    return static_cast<long long>(x) * (x - 1) / 2 % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    n = s.size();
    std::transform(s.rbegin(), s.rend(), a + 1, [&](char c) -> int {
        if ('a' <= c && c <= 'z') return c - 'a';
        if ('A' <= c && c <= 'Z') return c - 'A' + 26;
        return c - '0' + 52;
    });

    for (int i = 1; i <= n; i++) {
        std::copy(std::begin(pre[i - 1]), std::end(pre[i - 1]), std::begin(pre[i]));
        pre[i][a[i]]++;
    }

    for (int i = n; i; i--) {
        std::copy(std::begin(suf[i + 1]), std::end(suf[i + 1]), std::begin(suf[i]));
        suf[i][a[i]]++;
    }

    for (int j = 0; j < M; ++j) {
        same = (same + c2(pre[n][j])) % mod;
    }

    for (int i = 1; i <= n; i++) {
        same = ((same - suf[i + 1][a[i]]) % mod + mod) % mod;

        for (int j = 0; j < M; j++) {
            if (j == a[i]) continue;

            ans = (ans + static_cast<long long>(f2[j][a[i]]) * ((c2(n - i - suf[i + 1][a[i]] - suf[i + 1][j]) - ((same - (c2(suf[i + 1][j]) + c2(suf[i + 1][a[i]]))) % mod + mod) % mod) % mod + mod) % mod) % mod;
        }

        for (int j = 0; j < M; j++) {
            if (j == a[i]) continue;

            f2[a[i]][j] = (f2[a[i]][j] + f1[a[i]][j]) % mod;
        }

        for (int j = 0; j < M; j++) {
            if (j == a[i]) continue;

            f1[j][a[i]] = (f1[j][a[i]] + pre[i - 1][j]) % mod;
        }
    }

    cout << ans << endl;

    return 0;
}
