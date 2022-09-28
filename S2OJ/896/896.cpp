#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 6005;
const int mod = 1e9 + 7;

int n, f[N][2], ans;
std::pair<int, int> a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    std::sort(a + 1, a + 1 + n);

    f[1][0] = f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i][0] = f[i][1] = 1;

        for (int j = i - 1; j; j--) {
            if (a[j].second > a[i].second) {
                f[j][1] = (f[j][1] + f[i][0]) % mod;
            } else {
                f[i][0] = (f[i][0] + f[j][1]) % mod;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = (static_cast<long long>(ans) + f[i][0] + f[i][1] - 1) % mod;
    }

    cout << ans << endl;

    return 0;
}
