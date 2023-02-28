#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
const char endl = '\n';

void solve() {
    int n;
    bool flag = false;
    std::unordered_map<std::string, bool> map, map2;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        std::string s;

        cin >> s;

        map[s] = true;
        if (s.size() > 1) map2[s.substr(0, s.size() - 1)] = true;

        std::reverse(s.begin(), s.end());

        if (map.count(s) || map2.count(s)) flag = true;
        if (s.size() > 1 && map.count(s.substr(0, s.size() - 1))) flag = true;
    }

    cout << (flag ? "YES" : "NO") << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) solve();

    return 0;
}
