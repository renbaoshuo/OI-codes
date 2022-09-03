#include <iostream>
#include <set>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m, k, ans[N];
std::set<std::pair<int, int>> set;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        set.emplace(x, i);
    }

    int x = set.begin()->first,
        cnt = 1;

    ans[set.begin()->second] = 1;
    set.erase(set.begin());

    for (int i = 2; i <= n; i++) {
        auto it = set.lower_bound(std::make_pair(x + k + 1, 0));

        if (it != set.end()) {
            ans[it->second] = cnt;
        } else {
            it = set.begin();
            ans[it->second] = ++cnt;
        }

        x = it->first;
        set.erase(it);
    }

    cout << cnt << endl;

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    cout << endl;

    return 0;
}
