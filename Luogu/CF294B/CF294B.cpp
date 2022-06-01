#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, v[N], w[N], f[N * N], sum, ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
        sum += v[i];
    }

    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= v[i]; j--) {
            f[j] = std::min(f[j], f[j - v[i]] + w[i]);
        }
    }

    for (int i = sum; i >= 0; i--) {
        if (f[i] <= sum - i) {
            ans = sum - i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
