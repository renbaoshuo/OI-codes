#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, a, b, winner,
    cnt_le_a, cnt_le_b, cnt_le_2a, cnt_rest,
    ans_winner, ans_first, ans_second;
int fac[N], inv[N], fac_inv[N];
std::vector<int> v;

enum Winner {
    Alice = 0,
    Bob = 1,
};

int C(int n, int m) {
    if (n < m || n < 0 || m < 0) return 0;
    return static_cast<long long>(fac[n]) * fac_inv[m] % mod * fac_inv[n - m] % mod;
}

constexpr int binpow(int a, int b, int mod = ::mod) {
    int res = 1;
    a %= mod;

    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % mod;
        a = static_cast<long long>(a) * a % mod;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = static_cast<long long>(fac[i - 1]) * i % mod;
    }

    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = static_cast<long long>(mod - (mod / i)) * inv[mod % i] % mod;
    }

    fac_inv[0] = fac_inv[1] = 1;
    for (int i = 2; i < N; i++) {
        fac_inv[i] = static_cast<long long>(fac_inv[i - 1]) * inv[i] % mod;
    }

    cin >> n >> a >> b;

    if (a < b) {
        winner = Winner::Alice;
    } else {
        std::swap(a, b);
        winner = Winner::Bob;
    }

    std::copy_n(std::istream_iterator<int>(cin), n, std::back_inserter(v));
    std::transform(v.begin(), v.end(), v.begin(), std::bind(std::modulus<int>(), std::placeholders::_1, a + b));
    std::for_each(v.begin(), v.end(), [&](int x) {
        if (x < a) cnt_le_a++;            // [1, a)
        else if (x < b) cnt_le_b++;       // [a, b)
        else if (x < 2 * a) cnt_le_2a++;  // [b, 2a)
        else cnt_rest++;                  // [2a, a + b)
    });

    for (int i = 0; i <= cnt_le_2a; i++) {
        if (i % 2 == 0) {
            ans_first = (static_cast<long long>(ans_first) + static_cast<long long>(C(cnt_le_2a, i)) * cnt_rest % mod) % mod;
            ans_second = (static_cast<long long>(ans_second) + C(cnt_le_2a, i)) % mod;
        } else {  // i % 2 == 1
            ans_first = (static_cast<long long>(ans_first) + C(cnt_le_2a, i)) % mod;
        }
    }

    ans_first = static_cast<long long>(ans_first) * binpow(2, cnt_le_a) % mod;
    ans_second = static_cast<long long>(ans_second) * binpow(2, cnt_le_a) % mod;
    ans_winner = ((static_cast<long long>(binpow(2, n)) - ans_first - ans_second) % mod + mod) % mod;

    if (winner == Winner::Alice) {
        cout << ans_winner << ' ' << 0 << ' ' << ans_first << ' ' << ans_second << endl;
    } else {
        cout << 0 << ' ' << ans_winner << ' ' << ans_first << ' ' << ans_second << endl;
    }

    return 0;
}
