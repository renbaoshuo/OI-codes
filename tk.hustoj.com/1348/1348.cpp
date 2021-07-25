#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<string> args, file;
    stringstream ss;
    ss << s;
    while (ss >> s) {
        args.push_back(s);
    }
    int count = 10;
    if (args.size() >= 2) count = -atoi(args[1].c_str());
    while (getline(cin, s)) file.push_back(s);
    for (int i = max((int)file.size() - count, 0); i < file.size(); i++) {
        cout << file[i] << endl;
    }
    return 0;
}
