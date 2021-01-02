#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int n, m, t, p[5000050], inv[10000005];

int read() {
    int res = 0;
    char ch = getchar();
    while (!isdigit(ch) && !isalpha(ch)) {
        ch = getchar();
    }
    if (ch >= 'A') {
        return ch - 64 + n;
    }
    while (isdigit(ch)) {
        res = res * 10 + ch - 48;
        ch = getchar();
    }
    return res;
}

long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    cin >> n;
    p[1] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        if (!inv[m]) {
            inv[m] = binpow(m, mod - 2);
        }
        p[i] = (long long)p[i] * inv[m] % mod;
        for (int j = 1; j <= m; j++) {
            t = read();
            p[t] = (p[t] + p[i]) % mod;
        }
    }
    for (int i = 1; i <= 26; i++) {
        cout << p[n + i] << ' ';
    }
    cout << endl;
    return 0;
}
