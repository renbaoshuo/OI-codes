#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    std::vector<int> a;
    std::vector<std::vector<int>> ans;

    cin >> n;

    for (int i = 1, x; i <= n * (n - 1) / 2; i++) {
        cin >> x;

        a.emplace_back(x);
    }

    std::sort(a.begin(), a.end());

    for (int i = a[0] >> 1; i; i--) {
        int b = a[0] - i,
            c = a[1] - i;

        if (*std::lower_bound(a.begin(), a.end(), b + c) != b + c) continue;

        std::vector<int> v;
        std::unordered_map<int, int> map;

        for (int x : a) map[x]++;

        v.emplace_back(i);
        map[i + b]--;
        v.emplace_back(b);
        map[i + c]--;
        v.emplace_back(c);
        map[b + c]--;

        bool flag = false;
        for (int j = 2; j < a.size() && !flag; j++) {
            if (!map[a[j]]) continue;

            for (int x : v) {
                if (!map.count(x + a[j] - i) || !map[x + a[j] - i]) {
                    flag = true;

                    break;
                }

                map[x + a[j] - i]--;
            }

            v.emplace_back(a[j] - i);
        }

        if (!flag) ans.emplace_back(v);
    }

    cout << ans.size() << endl;

    std::sort(ans.begin(), ans.end(), std::greater<>());

    for (auto item : ans) {
        for (int x : item) {
            cout << x << ' ';
        }

        cout << endl;
    }

    return 0;
}
