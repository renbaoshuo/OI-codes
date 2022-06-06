#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <array>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, m, cnt[N], id[N], px[N], sa[N], height[N];
std::string s;
std::array<int, N> rk, rk1;

void get_sa() {
    for (int i = 1; i <= n; i++) ++cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i; i--) sa[cnt[rk[i]]--] = i;

    for (int w = 1, p = 0, i;; w <<= 1, m = p) {
        for (i = n, p = 0; i > n - w; i--) id[++p] = i;
        for (int i = 1; i <= n; i++) {
            if (sa[i] > w) id[++p] = sa[i] - w;
        }

        std::fill(cnt, cnt + 1 + m, 0);

        for (int i = 1; i <= n; i++) ++cnt[px[i] = rk[id[i]]];
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i; i--) sa[cnt[px[i]]--] = id[i];

        rk1 = rk;
        for (i = 1, p = 0; i <= n; i++) {
            if (rk1[sa[i]] == rk1[sa[i - 1]] && rk1[sa[i] + w] == rk1[sa[i - 1] + w]) {
                rk[sa[i]] = p;
            } else {
                rk[sa[i]] = ++p;
            }
        }

        if (p == n) {
            for (int i = 1; i <= n; i++) sa[rk[i]] = i;

            break;
        }
    }
}

void get_height() {
    for (int i = 1, k = 0; i <= n; i++) {
        if (!rk[i]) continue;
        if (k) k--;

        while (s[i + k] == s[sa[rk[i] - 1] + k]) k++;

        height[rk[i]] = k;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = s.size();
    m = 300;
    s = ' ' + s;

    get_sa();
    get_height();

    for (int i = 1; i <= n; i++) {
        cout << sa[i] << ' ';
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << height[i] << ' ';
    }
    cout << endl;

    return 0;
}
