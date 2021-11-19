#include <bits/stdc++.h>

using namespace std;

int m;
string s;

int main() {
    cin >> m >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            continue;
        }
        if (i != 0) {
            cout << '+';
        }
        cout << s[i] << '*' << m << '^' << s.size() - i - 1;
    }
    cout << endl;
    return 0;
}