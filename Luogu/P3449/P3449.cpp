#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e6 + 5;

int n;
long long ans;
std::string s[N];
std::unordered_map<std::string, int> map;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, _; i <= n; i++) {
        cin >> _ >> s[i];

        map[s[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        std::string str, str1(s[i]);
        str.reserve(s[i].size());
        str1.reserve(s[i].size() << 1);

        for (char c : s[i]) {
            str.push_back(c);
            str1.push_back(c);

            if (map.count(str) && str1 == str + s[i]) {
                ans += static_cast<long long>(map[str]) * 2;
            }
        }
    }

    cout << ans - n << endl;

    return 0;
}
