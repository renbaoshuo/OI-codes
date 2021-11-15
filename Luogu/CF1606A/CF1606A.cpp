#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main() {
    cin >> t;
    while (t--) {
        cin >> s;
        s[0] = *s.rbegin();
        cout << s << endl;
    }
    return 0;
}
