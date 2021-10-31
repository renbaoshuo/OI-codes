#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << s << endl;
        return 0;
    }
    while (s.size() && *(s.end() - 1) == '/') {
        s.erase(s.end() - 1);
    }
    if (!s.size()) {
        cout << "/" << endl;
        return 0;
    }
    for (string::iterator it = s.begin(); it != s.end(); it++) {
        if (it + 1 != s.end() && *it == '/' && *(it + 1) == '/') {
            s.erase(it + 1);
            it--;
        }
    }
    cout << s << endl;
    return 0;
}
