#include <iostream>
#include <algorithm>
#include <set>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, k, ans;
std::pair<int, int> a[N];
std::multiset<int> set;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    std::sort(a + 1, a + 1 + n, [&](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second < b.second;
    });

    for (int i = 1; i <= k; i++) set.insert(0);

    for (int i = 1; i <= n; i++) {
        auto it = set.upper_bound(a[i].first);

        if (it != set.begin()) {
            set.erase(--it);
            set.insert(a[i].second);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
