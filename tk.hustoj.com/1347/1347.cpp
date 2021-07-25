#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<string> args;
    stringstream ss;
    ss << s;
    while (ss >> s) {
        args.push_back(s);
    }
    int count = 10;
    if (args.size() >= 2) count = -atoi(args[1].c_str());
    while (getline(cin, s)) {
        if (count-- > 0) {
            cout << s << endl;
        }
    }
    return 0;
}