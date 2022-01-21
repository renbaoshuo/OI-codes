#include <iostream>
#include <set>

using std::cin;
using std::cout;
using std::endl;

const int N = 500005,
          P = 505;

int n, m, l, r, p, a[N];
long long sum[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        long long ans = 0x3f3f3f3f;
        cin >> l >> r >> p;
        if (r - l >= p) {
            cout << 0 << endl;
            continue;
        }
        std::set<long long> s;
        s.insert(0);
        sum[l - 1] = 0;
        for (int i = l; i <= r; i++) {
            sum[i] = (sum[i - 1] + a[i]) % p;
            ans = std::min(ans, sum[i] - *(--s.upper_bound(sum[i])));
            s.insert(sum[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
