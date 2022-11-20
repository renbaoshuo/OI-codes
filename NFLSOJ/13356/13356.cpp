#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

// using std::cin;
// using std::cout;
std::ifstream cin("rev.in");
std::ofstream cout("rev.out");
const char endl = '\n';

std::string s, t;
std::vector<std::pair<int, int>> ans;

bool check() {
    if (std::count(s.begin(), s.end(), '1') != std::count(t.begin(), t.end(), '1')) {
        return false;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[i]) continue;

        int cnt = 0;
        bool flag = false;

        for (int j = i; j < s.size(); j++) {
            if (s[j] == '1') cnt++;

            if (s[j] == t[i] && cnt % 2 == 0) {
                flag = true;
                ans.emplace_back(i + 1, j + 1);
                std::reverse(s.begin() + i, s.begin() + j + 1);
                break;
            }
        }

        if (!flag) return false;
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> t;

    if (check()) {
        cout << "YES" << endl
             << ans.size() << endl;

        for (auto e : ans) {
            cout << e.first << ' ' << e.second << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
