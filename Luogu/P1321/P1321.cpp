// R38664427

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int boy, girl;
    boy = girl = 0;
    cin >> s;

    for (int i = 0; i < s.size() - 2; i++) {
        boy += (s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y');
    }
    for (int i = 0; i < s.size() - 3; i++) {
        girl += (s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' || s[i + 3] == 'l');
    }

    cout << boy << endl
         << girl << endl;
    return 0;
}
