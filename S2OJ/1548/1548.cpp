#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n;
long long w[N], ans;
std::mt19937 rng(std::random_device{}());

int random(int l, int r) {
    return std::uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    while (clock() <= 0.6 * CLOCKS_PER_SEC) {
        int p = random(1, n);

        std::unordered_map<long long, int> cnt;
        std::vector<long long> v;

        for (int i = 1; i <= n; i++) {
            cnt[std::__gcd(w[i], w[p])]++;
        }

        for (int i = 1; i <= w[p] / i; i++) {
            if (w[p] % i == 0) {
                v.push_back(i);
                if ((w[p] / i) != i) v.push_back(w[p] / i);
            }
        }

        for (long long x : v) {
            int sum = 0;

            for (long long y : v) {
                if (y % x == 0) {
                    sum += cnt[y];
                }
            }

            if (sum >= (n + 1) / 2) {
                ans = std::max(ans, x);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
