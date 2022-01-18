#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int N = 1000005;

long long l, r, cnt, primes[N], ans;
bool vis[N];

int main() {
    for (int i = 2; i <= 1000000; i++) {
        if (!vis[i]) {
            primes[++cnt] = i;
            for (int j = i; j <= 1000000; j += i) {
                vis[j] = true;
            }
        }
    }
    cin >> l >> r;
    memset(vis, 0x00, sizeof(vis));
    l = std::max(l, 2ll);
    for (int i = 1; i <= cnt; i++) {
        long long p = primes[i];
        for (long long j = std::max((l + p - 1) / p * p, p * 2); j <= r; j += p) {
            vis[j - l + 1] = true;
        }
    }
    for (int i = 1; i <= r - l + 1; i++) {
        if (!vis[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
