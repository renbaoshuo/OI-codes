#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, s[N << 1], f[N];
std::pair<int, int> a[N];

int pow(int a, int b) {
    int res = 1;

    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;

        s[a[i].second]++;
    }

    std::sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n << 1; i++) {
        s[i] += s[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        f[i] = (f[i - 1] * 2 % mod + pow(2, s[a[i].first - 1]) % mod) % mod;
    }

    cout << f[n] << endl;

    return 0;
}
