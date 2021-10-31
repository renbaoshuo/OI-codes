#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    cout << setiosflags(ios::uppercase) << "#" << setfill('0') << setw(2) << hex << (255 - ((isdigit(s[1]) ? s[1] - '0' : s[1] - 'A' + 10) * 16 + (isdigit(s[2]) ? s[2] - '0' : s[2] - 'A' + 10))) << setfill('0') << setw(2) << hex << (255 - ((isdigit(s[3]) ? s[3] - '0' : s[3] - 'A' + 10) * 16 + (isdigit(s[4]) ? s[4] - '0' : s[4] - 'A' + 10))) << setfill('0') << setw(2) << hex << (255 - ((isdigit(s[5]) ? s[5] - '0' : s[5] - 'A' + 10) * 16 + (isdigit(s[6]) ? s[6] - '0' : s[6] - 'A' + 10))) << endl;
    return 0;
}
