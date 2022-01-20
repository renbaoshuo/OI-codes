#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int N = 500005;
const int P = 505;

int n, m, l, r, p, a[N];
long long sum[N];
bool vis[P];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        long long ans = 0x3f3f3f3f;
        memset(vis, 0x00, sizeof(vis));
        vis[0] = true;
        cin >> l >> r >> p;
        if (r - l >= p) {
            cout << 0 << endl;
            continue;
        }
        sum[l - 1] = 0;
        for (int i = l; i <= r; i++) {
            sum[i] = (sum[i - 1] + a[i]) % p;
            for (int j = sum[i]; j >= 0; j--) {
                if (vis[j]) {
                    ans = std::min(ans, sum[i] - j);
                }
            }
            vis[sum[i]] = true;
        }
        cout << ans << endl;
    }
    return 0;
}
