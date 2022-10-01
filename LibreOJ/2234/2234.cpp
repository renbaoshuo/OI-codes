#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

int cnt;
long long s, ans[500005];
int p, primes[50005];
bool not_prime[50005];

bool is_prime(long long x) {
    if (x < 2) return false;

    for (int i = 2; static_cast<long long>(i) * i <= x; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

void dfs(long long now, int pos, long long sum) {
    if (now == 1) {
        ans[++cnt] = sum;

        return;
    }

    if (is_prime(now - 1) && now > primes[pos]) {
        ans[++cnt] = (now - 1) * sum;
    }

    for (int i = pos;
         static_cast<long long>(primes[i]) * primes[i] <= now;
         i++) {
        for (long long t = primes[i],
                       s = t + 1;
             s <= now;
             s += t *= primes[i]) {
            if (now % s == 0) {
                dfs(now / s, i + 1, sum * t);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i <= 50000; i++) {
        if (!not_prime[i]) primes[++p] = i;

        for (int j = 1; i * primes[j] <= 50000; j++) {
            not_prime[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }

    while (cin >> s) {
        cnt = 0;

        dfs(s, 1, 1);
        std::sort(ans + 1, ans + cnt + 1);

        cout << cnt << endl;

        if (cnt) {
            for (int i = 1; i <= cnt; i++) {
                cout << ans[i] << ' ';
            }

            cout << endl;
        }
    }

    return 0;
}
