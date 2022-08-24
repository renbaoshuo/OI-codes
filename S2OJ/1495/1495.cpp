#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, v[N], w[N], f[N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= v[i]; j--) {
            f[j] = std::max(f[j], f[j - v[i]] + w[i]);
            ans = std::max(ans, f[j]);
        }
    }

    cout << ans << endl;

    return 0;
}
