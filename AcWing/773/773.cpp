#include <bits/stdc++.h>

using namespace std;

string s, s1;

int main() {
    while (cin >> s >> s1) {
        bool flag = false;
        char c = 'z';
        while (!flag) {
            if (s.find_first_of(c) != string::npos) {
                s.insert(s.find_first_of(c) + 1, s1);
                flag = true;
                break;
            }
            c--;
        }
        cout << s << endl;
    }

    return 0;
}
