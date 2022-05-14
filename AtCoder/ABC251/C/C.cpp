#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
const char endl = '\n';

int n;
std::string s;
std::unordered_map<std::string, bool> map;
std::pair<int, int> ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> s >> x;

        if (!map.count(s)) {
            map[s] = true;
            if (x > ans.first) {
                ans = std::make_pair(x, i);
            }
        }
    }

    cout << ans.second << endl;

    return 0;
}
