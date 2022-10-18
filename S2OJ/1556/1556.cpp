#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int a, b, c, d;
        std::vector<std::pair<char, int>> ans;

        cin >> a >> b >> c >> d;

        if ((a == 0 && b == -1) || (c == 0 && d == -1)) {
            ans.emplace_back('B', 1);
            std::swap(a, b), std::swap(c, d);
            a = -a, c = -c;
        } else if ((a == -1 && b == 0) || (c == -1 && d == 0)) {
            ans.emplace_back('B', -1);
            std::swap(a, b), std::swap(c, d);
            b = -b, d = -d;
        }

        if (a == 0 && b == 1) {
            if (d) ans.emplace_back('A', d);
            ans.emplace_back('B', -1);
        } else if (b == 0 && a == 1) {
            ans.emplace_back('B', 1);
            if (c) ans.emplace_back('A', c);
            ans.emplace_back('B', -1);
        } else if (c == 0 && d == 1) {
            ans.emplace_back('A', -b);
        } else {
            ans.emplace_back('B', 1);
            if (a) ans.emplace_back('A', -a);
        }

        std::reverse(ans.begin(), ans.end());

        cout << ans.size() << endl;

        for (auto o : ans) {
            cout << o.first << ' ' << -o.second << endl;
        }
    }

    return 0;
}
