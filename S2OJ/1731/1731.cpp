#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int nxt[N], f[N][2], p[N], a[N], b[N];
std::string s;

int binpow(int a, int b) {
    int res = 1;

    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % mod;
        a = static_cast<long long>(a) * a % mod;
        b >>= 1;
    }

    return res;
}

signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    s = ' ' + s;

    for (int i = 2, j = 0; i < s.size(); i++) {
        while (j && s[i] != s[j + 1]) j = nxt[j];
        if (s[i] == s[j + 1]) j++;
        nxt[i] = j;
    }

    for (int i = 1; i < s.size(); i++) {
        bool x = s[i] - '0';
        f[i - 1][x] = i;
        p[i - 1] = f[i - 1][x ^ 1] = f[nxt[i - 1]][x ^ 1];
    }

    a[0] = 1;

    for (int i = 1; i < s.size(); i++) {
        a[i] = (static_cast<long long>(a[i - 1]) * 2 - a[p[i - 1]]) % mod;
        b[i] = (static_cast<long long>(b[i - 1]) * 2 - b[p[i - 1]] - 2) % mod;
    }

    cout << (mod - (static_cast<long long>(b[s.size() - 1]) * binpow(a[s.size() - 1], mod - 2)) % mod) % mod << endl;

    return 0;
}
