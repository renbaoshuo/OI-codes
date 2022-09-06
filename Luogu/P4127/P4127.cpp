#include <iostream>
#include <bitset>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

long long a, b, f[20][200][200], ans;
int c[20], p;

long long dfs(int len, int s, int x, bool limit) {
    if (s + 9 * len < p) return 0;
    if (!limit && f[len][s][x] != -1) return f[len][s][x];
    if (!len) return s == p && x == 0;

    int n = limit ? c[len] : 9;
    long long res = 0;

    for (int i = 0; i <= n && i + s <= p; i++)
        res += dfs(len - 1, s + i, (x * 10 + i) % p, limit && (i == c[len]));

    if (!limit) f[len][s][x] = res;

    return res;
}

long long calc(long long x) {
    int cnt = 0;

    while (x) {
        c[++cnt] = x % 10;
        x /= 10;
    }

    long long res = 0;

    for (p = 1; p <= cnt * 9; p++) {
        memset(f, 0xff, sizeof(f));
        res += dfs(cnt, 0, 0, 1);
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    cout << calc(b) - calc(a - 1) << endl;

    return 0;
}
