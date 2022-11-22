#include <iostream>
#include <cmath>
#include <fstream>
#include <functional>
#include <utility>
#include <vector>

// using std::cin;
// using std::cout;
std::ifstream cin("divisor.in");
std::ofstream cout("divisor.out");
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        int x = n, lst = 0;
        std::vector<std::pair<int, int>> a;
        std::vector<int> ans;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                int cnt = 0;

                while (x % i == 0) x /= i, cnt++;

                a.emplace_back(i, cnt);
            }
        }

        if (x > 1) a.emplace_back(x, 1);

        std::function<void(int, int)> dfs = [&](int p, int x) -> void {
            if (p == a.size()) {
                ans.emplace_back(lst = x);

                return;
            }

            if (lst % a[p].first) {
                for (int i = 0; i <= a[p].second; i++) {
                    dfs(p + 1, x);
                    x *= a[p].first;
                }
            } else {
                x *= std::pow(a[p].first, a[p].second);
                for (int i = 0; i <= a[p].second; i++) {
                    dfs(p + 1, x);
                    x /= a[p].first;
                }
            }
        };

        dfs(0, 1);

        cout << ans.size() << endl;

        for (int x : ans) cout << x << ' ';

        cout << endl;
    }

    return 0;
}
