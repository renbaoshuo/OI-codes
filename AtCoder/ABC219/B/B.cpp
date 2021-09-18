#include <bits/stdc++.h>

using namespace std;

string s[4], t;

int main() {
    cin >> s[1] >> s[2] >> s[3] >> t;
    for (auto c : t) {
        cout << s[c - '0'];
    }
    cout << endl;
    return 0;
}
