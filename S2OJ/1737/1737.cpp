#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e7 + 5;

long long l, r, k, ans;
int cnt, primes[N];
bool vis[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> r >> k;

    for (long long i = 2; i * i <= r && i <= k; i++) {
        for (long long j = std::max(((l + i - 1) / i) * i, i * 2); j <= r; j += i) {
            vis[j - l + 1] = true;
        }
    }

    for (long long i = l; i <= r; i++) {
        if (!vis[i - l + 1]) ans ^= i;
    }

    cout << ans << endl;

    return 0;
}
