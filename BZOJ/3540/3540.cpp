#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, f[N << 1], ans;
std::pair<int, char> cows[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(f, 0x3f, sizeof(f));

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    std::sort(cows + 1, cows + 1 + n);

    f[n] = cows[1].first;
    for (int i = 2, x = n; i <= n; i++) {
        x += cows[i - 1].second == 'W' ? -1 : 1;
        f[x] = std::min(f[x], cows[i].first);
    }

    for (int i = n << 1; i; i--) {
        f[i] = std::min(f[i], f[i + 2]);
    }

    for (int i = 1, x = n; i <= n; i++) {
        x += cows[i].second == 'W' ? -1 : 1;
        ans = std::max(ans, cows[i].first - f[x]);
    }

    cout << ans << endl;

    return 0;
}
