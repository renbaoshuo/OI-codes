#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e7 + 5;

int n, s, b, c, d, a[N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s >> b >> c >> d;

    for (int i = 1; i <= n; i++) {
        a[i] = i;
        s = (static_cast<long long>(s) * b + c) % d;
        std::swap(a[i], a[s % i + 1]);
    }

    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, i - a[i]);
    }

    cout << ans << endl;

    return 0;
}
