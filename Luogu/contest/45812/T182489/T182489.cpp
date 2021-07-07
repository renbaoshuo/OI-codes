#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int main() {
    int n, k;
    cin >> n >> k;
    int v = 1, q = 1;
    for (int i = 0; i < n - k; i++) {
        v = 2ll * v % mod;
    }
    for (int i = n - k + 1; i <= n; i++) {
        v = 1ll * i * v % mod;
    }
    for (int i = 1; i <= k; i++) {
        q = 1ll * i * q % mod;
    }
    int a = 1, e = mod - 2;
    while (e) {
        if (e & 1) {
            a = 1ll * a * q % mod;
        }
        q = 1ll * q * q % mod;
        e >>= 1;
    }
    cout << 1ll * v * a % mod << endl;
}
