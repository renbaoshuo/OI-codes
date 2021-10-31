#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    bool flag = true;
    while (cin >> s) {
        if (flag) {
            flag = false;
            cout << s.size();
        } else {
            cout << ',' << s.size();
        }
    }
    return 0;
}
