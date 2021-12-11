#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int n;
std::string s;
std::map<std::string, int> m;
std::pair<std::string, int> ans;

int main() {
    cin >> n;
    while (n--) {
        cin >> s;
        m[s]++;
    }
    for (auto i : m) {
        if (i.second > ans.second) {
            ans = i;
        }
    }
    cout << ans.first << endl;
    return 0;
}
