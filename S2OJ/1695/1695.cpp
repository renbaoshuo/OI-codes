#include <iostream>
#include <bitset>
#include <cctype>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 15 + 1,
          M = 2e6 + 5;

int n, cnt, a[M], op[M];
std::string s;
std::bitset<1 << N> g, h[1 << N][2], b, b0, b1, ans;

inline int get(std::string s) {
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            x = (x << 1) + (x << 3) + (s[i] - '0');
        }
    }
    return x;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    for (int i = 0; i < s.size(); i++) {
        g.set(i, s[i] == '1');
    }

    int f = 1;
    while (cin >> s, s != "END") {
        if (s == "N") f = -f;
        else if (s == "A") op[cnt] = 1;
        else if (s == "O") op[cnt] = 0;
        else if (s[0] == 'a') a[++cnt] = f * get(s), f = 1;
        else a[++cnt] = f * 1e6 * (s == "1" ? 1 : -1), f = 1;
    }

    for (int s = 0; s < 1 << n; s++) {
        for (int i = 0; i < n; i++) {
            h[i][(s >> i) & 1].set(s);
        }
    }

    b.set();
    for (int i = 0; i < 1 << n; i++) b1.set(i);
    std::bitset<1 << N> sum = b;

    for (int i = 1; i <= cnt; i++) {
        if (a[i] == -1e6) sum &= b0;
        else if (a[i] == 1e6) sum &= b1;
        else if (a[i] > 0) sum &= h[n - a[i]][1];
        else sum &= h[n + a[i]][0];
        if (!op[i]) ans |= sum, sum = b;
    }

    cout << (ans == g ? "YES" : "NO") << endl;

    return 0;
}
