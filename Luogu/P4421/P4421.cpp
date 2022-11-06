#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 20005;

int n, ans;
std::string s[N];
std::unordered_map<std::string, int> map;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        std::unordered_map<std::string, bool> map2;

        cin >> s[i];

        for (int j = 0; j < s[i].size(); j++) {
            for (int k = j; k < s[i].size(); k++) {
                std::string t = s[i].substr(j, k - j + 1);

                if (!map2[t]) {
                    map[t]++;
                    map2[t] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans += map[s[i]] - 1;
    }

    cout << ans << endl;

    return 0;
}
