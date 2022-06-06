#include <iostream>
#include <algorithm>
#include <array>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, sa[N], height[N];
std::string s;
std::array<int, N> rk, rk1;

void get_sa() {
    for (int i = 1; i <= n; i++) {
        sa[i] = i;
        rk[i] = s[i];
    }

    for (int w = 1; w < n; w <<= 1) {
        std::sort(sa + 1, sa + 1 + n, [&](int a, int b) {
            return rk[a] == rk[b] ? rk[a + w] < rk[b + w] : rk[a] < rk[b];
        });

        rk1 = rk;

        for (int i = 1, p = 0; i <= n; i++) {
            if (rk1[sa[i]] == rk1[sa[i - 1]] && rk1[sa[i] + w] == rk1[sa[i - 1] + w]) {
                rk[sa[i]] = p;
            } else {
                rk[sa[i]] = ++p;
            }
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
    s = ' ' + s;

    get_sa();
    get_height();

    for (int i = 1; i <= n; i++) {
        cout << sa[i] << ' ';
    }
    cout << endl;

    for (int i = 2; i <= n; i++) {
        cout << height[i] << ' ';
    }
    cout << endl;

    return 0;
}
