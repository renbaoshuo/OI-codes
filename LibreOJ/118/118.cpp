#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

std::string s, re;

int main() {
    std::ios::sync_with_stdio(false);
    while (cin >> re >> s) {
        cout << (std::regex_match(s, std::regex(re)) ? "Yes" : "No") << endl;
    }
    return 0;
}
