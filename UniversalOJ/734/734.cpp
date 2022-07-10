#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n;
std::string s[N];
std::unordered_map<std::string, std::pair<std::string, bool>> def;

std::string dfs(std::string s) {
    std::string r;

    for (int i = 0, j; i < s.size(); i += j) {
        for (j = 0; i + j < s.size() &&
                    ('0' <= s[i + j] && s[i + j] <= '9' ||
                     'a' <= s[i + j] && s[i + j] <= 'z' ||
                     'A' <= s[i + j] && s[i + j] <= 'Z' || s[i + j] == '_');
             j++)
            ;
        if (j) {
            std::string tmp = s.substr(i, j), tmp2;

            if (def.count(tmp) && !def[tmp].second) {
                def[tmp].second = true;
                r += dfs(def[tmp].first);
                def[tmp].second = false;
            } else {
                r += tmp;
            }
        } else {
            r += s[i++];
        }
    }

    return r;
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        std::getline(cin, s[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (s[i][0] == '#') {
            if (s[i].substr(1, 6) == "define") {
                int p = s[i].find_first_of(' ', 8);
                std::string name = s[i].substr(8, p - 8),
                            content = s[i].substr(p + 1);
                def[name] = std::make_pair(content, false);
            } else {  // s[i].substr(1, 6) == "undef"
                std::string name = s[i].substr(7);
                def.erase(name);
            }
            cout << endl;
        } else {
            cout << dfs(s[i]) << endl;
        }
    }

    return 0;
}
