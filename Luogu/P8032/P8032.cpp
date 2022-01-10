#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

std::string s, w, p;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '{') {
            cout << p << c << endl;
            p += "  ";
        } else if (c == ',') {
            if (s[i - 1] == '}') continue;
            cout << p << w << c << endl;
            w.clear();
        } else if (c == '}') {
            if (!w.empty()) {
                cout << p << w << endl;
                w.clear();
            }
            p.erase(0, 2);
            cout << p << c;
            if (i + 1 != s.size() && s[i + 1] != '}') {
                cout << ',';
            }
            cout << endl;
        } else {
            w.push_back(c);
        }
    }
    return 0;
}
