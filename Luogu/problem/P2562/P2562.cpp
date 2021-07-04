#include <bits/stdc++.h>

using namespace std;

string work(string s) {
    if (s.find('1') == string::npos) {
        return "A";
    }
    if (s.find('0') == string::npos) {
        return "B";
    }
    return "C" + work(s.substr(0, s.size() / 2)) + work(s.substr(s.size() / 2));
}

int main() {
    string s;
    cin >> s;
    cout << work(s) << endl;
    return 0;
}
