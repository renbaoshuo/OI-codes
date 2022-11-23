#include <iostream>
#include <fstream>

// using std::cin;
// using std::cout;
std::ifstream cin("string.in");
std::ofstream cout("string.out");
const char endl = '\n';

const int N = 1e6 + 5;
const int mod = 998244353;

int a, b, inv[N << 2], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    inv[0] = inv[1] = 1;

    for (int i = 2; i <= a + a + b; i++) {
        inv[i] = static_cast<long long>(mod - mod / i) * inv[mod % i] % mod;
    }

    for (int i = 1; i <= a; i++) {
        ans = (static_cast<long long>(ans) + inv[2 * i - 1]) % mod;
    }

    for (int i = 1; i <= b; i++) {
        ans = (static_cast<long long>(ans) + inv[2 * a + i]) % mod;
    }

    cout << ans << endl;

    return 0;
}
