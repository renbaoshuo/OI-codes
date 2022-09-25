#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> t;
    s += t;
    cin >> t;
    s += t;
    cin >> t;
    s += t;
    for (int i = 0; i < 9; i++) {
        if (s[i] != s[8 - i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
