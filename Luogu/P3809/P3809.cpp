#include <iostream>
#include <algorithm>
#include <array>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n;
std::string s;
std::array<int, N> sa;
std::array<int, N << 1> rk, rk1;

void get_sa() {
    for (int i = 1; i <= n; i++) {
        sa[i] = i;
        rk[i] = s[i];
    }

    for (int w = 1; w < n; w <<= 1) {
        std::sort(sa.begin() + 1, sa.begin() + 1 + n, [&](auto x, auto y) {
            return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y];
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

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = s.size();
    s = ' ' + s;

    get_sa();

    for (int i = 1; i <= n; i++) {
        cout << sa[i] << ' ';
    }
    cout << endl;

    return 0;
}
