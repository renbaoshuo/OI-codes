#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';
const int N = 1e5 + 5,
          M = 3005;

int n, ans;
std::vector<long long> primes;
bool not_prime[N];
std::unordered_map<long long, int> map;
std::vector<std::pair<long long, long long>> data;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < M; i++) {
        if (!not_prime[i]) primes.emplace_back(i);

        for (auto p : primes) {
            if (i * p >= M) break;

            not_prime[i * p] = true;

            if (i % p == 0) break;
        }
    }

    cin >> n;

    for (int i = 1; i <= n; i++) {
        long long x, y = 1, z = 1;

        cin >> x;

        for (auto p : primes) {
            if (p * p > x) break;

            int t = 0;

            while (x % p == 0) {
                x /= p;
                t++;
            }

            t %= 3;

            if (t == 0) continue;

            for (int k = 1; k <= t; k++) y *= p;
            for (int k = 1; k <= 3 - t; k++) z *= p;
        }

        y *= x;

        if (x > 1) {
            long long t = std::sqrt(x);
            if (t * t == x) z *= std::sqrt(x);
            else z *= x * x;
        }

        map[y]++;
        data.emplace_back(y, z);
    }

    ans = map[1] > 0;

    for (auto o : data) {
        if (o.first == 1) continue;

        ans += std::max(map[o.first], map[o.second]);
        map[o.first] = map[o.second] = 0;
    }

    cout << ans << endl;

    return 0;
}
