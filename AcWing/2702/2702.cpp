#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, d, k, p;
int mu[50005], primes[50005], sum[50005];
bool vis[50005];

void getMobius(int n) {
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            primes[++p] = i;
            mu[i] = -1;
        }
        for (int j = 1; i * primes[j] <= n; j++) {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
            mu[i * primes[j]] = -mu[i];
        }
    }
}

int g(int k, int x) {
    return k / (k / x);
}

long long f(int a, int b, int k) {
    a = a / k, b = b / k;
    long long res = 0;
    int n = min(a, b);
    for (int l = 1, r; l <= n; l = r + 1) {
        r = min(n, min(g(a, l), g(b, l)));
        res += (long long)(sum[r] - sum[l - 1]) * (a / l) * (b / l);
    }
    return res;
}

int main() {
    cin >> n;
    getMobius(50000);
    for (int i = 1; i <= 50000; i++) {
        sum[i] = sum[i - 1] + mu[i];
    }
    while (n--) {
        cin >> a >> b >> c >> d >> k;
        cout << f(b, d, k) - f(a - 1, d, k) - f(b, c - 1, k) + f(a - 1, c - 1, k) << endl;
    }
    return 0;
}
