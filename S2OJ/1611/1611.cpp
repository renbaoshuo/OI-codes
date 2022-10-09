#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5,
          K = 55;

int n, k, a[N], pos[N], pre[N][K], nxt[N][K], prev[N], next[N];
long long ans;
std::set<int> set;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        pos[a[i]] = i;
    }

    for (int i = n; i; i--) {
        int p = pos[i];
        auto it = set.lower_bound(p);

        std::fill_n(pre[p], K, 0);
        std::fill_n(nxt[p], K, n + 1);
        pre[p][0] = nxt[p][0] = p;

        if (it != set.end()) {
            prev[*it] = p;
            next[p] = *it;

            for (int j = *it, l = 1; j && l <= k; j = next[j], l++) {
                nxt[p][l] = j;
            }
        }

        if (it != set.begin()) {
            it--;

            prev[p] = *it;
            next[*it] = p;

            for (int j = *it, l = 1; j && l <= k; j = prev[j], l++) {
                pre[p][l] = j;
            }
        }

        set.insert(p);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            ans += static_cast<long long>(a[i]) * (pre[i][j - 1] - pre[i][j]) * (nxt[i][k - j + 1] - nxt[i][k - j]);
        }
    }

    cout << ans << endl;

    return 0;
}
