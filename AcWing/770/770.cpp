#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, s1, s2;
    getline(cin, s);
    stringstream ss;
    ss << s;
    cin >> s1 >> s2;
    while (ss >> s) {
        if (s == s1) {
            cout << s2 << ' ';
        } else {
            cout << s << ' ';
        }
    }
    cout << endl;
    return 0;
}
