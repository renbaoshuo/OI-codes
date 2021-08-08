#include <bits/stdc++.h>

using namespace std;

int t, a, cnt, prime[100005];
bool flag, is_prime[1000005];

int eratosthenes(int n) {
    int p = 0;
    for (int i = 0; i <= n; i++) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            if (1ll * i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
    }
    return p;
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    cin >> t;
    cnt = eratosthenes(1000000);
    while (t--) {
        flag = false;
        cin >> a;
        for (int i = 0; i < cnt; i++) {
            if (binpow(a, prime[i], 10) % 10 == binpow(prime[i], a, 10) % 10) {
                cout << prime[i] << endl;
                flag = true;
                break;
            }
        }
        if (!flag) cout << -1 << endl;
    }
    return 0;
}
