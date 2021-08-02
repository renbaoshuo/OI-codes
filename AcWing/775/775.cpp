#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    vector<string> c;
    while (cin >> s) c.push_back(s);
    reverse(c.begin(), c.end());
    for (auto i : c) {
        cout << i << ' ';
    }
    return 0;
}
