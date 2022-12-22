#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int n, m, ans;
std::map<std::vector<int>, int> map;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    std::vector<int> s(m);

    map[s] = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        for (int j = 0; j < m; j++) {
            if (x >> j & 1) s[j]++;
        }

        if (!std::count(s.begin(), s.end(), 0)) {
            for (int& x : s) x--;
        }

        if (map.count(s)) {
            ans = std::max(ans, i - map[s]);
        } else {
            map[s] = i;
        }
    }

    cout << ans << endl;

    return 0;
}
