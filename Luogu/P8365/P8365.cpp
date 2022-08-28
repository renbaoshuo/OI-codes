#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;
const int mod = 1e9 + 7;

int n, a[N], b[N], ans = 1;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            ans = (static_cast<long long>(ans) + b[i]) % mod;
            a[i] = -1;
        }
    }

    long double max = ans;
    int max_id = -1;

    for (int i = 1; i <= n; i++) {
        if (~a[i]) {
            long double t = static_cast<long double>(static_cast<long long>(ans) + b[i]) / a[i];

            if (t > max) {
                max = t;
                max_id = i;
            }
        }
    }

    if (~max_id) {
        a[max_id] = -1;
        ans = (static_cast<long long>(ans) + b[max_id]) % mod;
    }

    for (int i = 1; i <= n; i++) {
        if (~a[i]) {
            ans = static_cast<long long>(ans) * a[i] % mod;
        }
    }

    cout << ans << endl;

    return 0;
}
