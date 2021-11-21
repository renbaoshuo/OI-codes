#include <bits/stdc++.h>

using namespace std;

const char mod[] = "0123456789X";

int t;
string s;

int main() {
    cin >> s;
    for (int i = 0, j = 0; i < 12; i++) {
        if (s[i] != '-') {
            t += (s[i] - '0') * ++j;
        }
    }
    if (s[12] != mod[t % 11]) {
        s[12] = mod[t % 11];
        cout << s << endl;
    } else {
        cout << "Right" << endl;
    }
    return 0;
}
